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
 * nvram_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is main() function of NVRAM module.
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
 *
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*
 * Include
 */
#include <string.h>
#include "nvram_msgid.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "syscomp_config.h"
#include "task_config.h"
#include "sysconf_statistics.h"     /* stack_statistics_struct */
#include "custom_em.h"
/* Factory mode, should not send ADC calibration data to BMT  */
#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#include "intrCtrl.h"               /* INT_BootMode */
#endif /* __MULTI_BOOT__ */

#ifdef __CCCIFS_SUPPORT__
#include "ccci.h"
#endif

#if defined(__MTK_TARGET__)
#include "SST_secure.h"
#endif

#include "fs_type.h"                /* FS_HANDLE */
#include "fs_func.h"                /* FS_Delete */
#include "fs_errcode.h"             /* FS_NO_ERROR */
#include "ex_item.h"                /* EX_LOG_T */

#include "nvram_main.h"
#include "nvram_interface.h"

#include "nvram_msg_handler.h"

#include "tst_msgid.h"

/*******************************************************
 *  External Function
 *******************************************************/
extern void MMISWChangeWarning(
                kal_uint8 type,
                kal_uint32 space,
                kal_uint8 const *codeversion,
                kal_uint8 const *diskversion);

extern void MMICheckDiskDisplay(void);


extern void *kal_tmp_mem_alloc(kal_uint32 size);
extern void kal_tmp_mem_free(void *mem_ptr);
extern kal_char *release_verno(void);
extern kal_char *release_branch(void);
extern kal_char *release_flavor(void);
extern kal_bool nvram_custom_lock_status(void);
extern void custom_nvram_config(void);

#if !defined(L4_NOT_PRESENT)
extern nvram_ef_sbp_modem_config_struct sbp_config; //defined in l4c_init.c
extern nvram_ef_sbp_modem_data_config_struct sbp_data_config; //defined in l4c_init.c
#endif

/*******************************************************
 * Define
 *******************************************************/
#define OVERHEAD_CLUSTER        5           /* extra space in bytes needed for conflict resolution. ex, report files */
#define DISPLAY_WARNING_TIME    1000        /* 1000 ticks = 4.6 sec */
#define MAX_CHANGE_ARRAY_SIZE   (nvram_ptr->ltable.total_LID + 1)

/*******************************************************
 *  Typedef
 *******************************************************/
typedef struct
{
    kal_bool checked;
    WCHAR diskfile[NVRAM_FILE_LEN + 1];
} diskTableEntry;

/*******************************************************
 *  Global Variable
 *******************************************************/
kal_mutexid g_nvram_imei_mutex = NULL;
kal_mutexid g_nvram_fs_mutex = NULL;

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
kal_bool bResetNvramData = KAL_FALSE;
#endif

nvram_context_type nvram_context;
nvram_context_type *nvram_ptr = &nvram_context;


/*******************************************************
 *  Local Function
 *******************************************************/

static kal_bool nvram_init_all_ldi(nvram_reset_category_enum reset_category);
static void nvram_scan_all_ldi(void);

static kal_bool nvram_supplementary_check(void);

/*******************************************************
 *  Local Variable
 *******************************************************/
static kal_uint32 BytesPerCluster;  /* will be set to exact value in nvram_get_disk_file_info */
static kal_uint32 *nvram_init_tmp_pool;
static diskTableEntry *DiskTable;
static kal_uint16 files_in_folder[NVRAM_FOLDER_TOTAL];
static kal_uint32 diskSize_of_folder[NVRAM_FOLDER_TOTAL];
static kal_uint32 *LIDChangeArray = NULL;   /* [count, lid1, lid2,..] ex. [3, 12, 29] */
static kal_uint32 LIDChanged = 0;
static kal_uint32 *LIDChangeArraySYS = NULL;        /* [count, lid1, lid2,..] ex. [3, 12, 29] */
static kal_uint32 LIDChangedSYS = 0;

/*****************************************************************************
 * FUNCTION
 *  nvram_create
 * DESCRIPTION
 *  NVRAM task create function
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *  success or fail
 *****************************************************************************/
kal_bool nvram_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct nvram_handler_info =
    {
        nvram_task_main,    /* task entry function */
        nvram_init,         /* task initialization function */
        nvram_reset        /* task reset handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & nvram_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_task_main
 * DESCRIPTION
 *  NVRAM task
 * PARAMETERS
 *  task_entry_ptr      [?]
 * RETURNS
 *  void
 *****************************************************************************/

#ifndef __MTK_TARGET__
  #ifdef _MSC_VER
    nvram_read_callback_struct __pragma(data_seg("_nvram_callback_tbl_begin")) _nvram_callback_tbl_begin_p = {0};
    
    #pragma comment(linker, "/MERGE:_nvram_callback_tbl_content=_nvram_callback_tbl_begin")
    
    nvram_read_callback_struct __pragma(data_seg("_nvram_callback_tbl_end")) _nvram_callback_tbl_end_p = {0};
    
    #pragma comment(linker, "/MERGE:_nvram_callback_tbl_end=_nvram_callback_tbl_begin")
  #else
    // section merge is moved to linker script for other compilers
    __attribute__ ((section("_nvram_callback_tbl_begin"))) nvram_read_callback_struct _nvram_callback_tbl_begin_p = {0};
    __attribute__ ((section("_nvram_callback_tbl_end"))) nvram_read_callback_struct _nvram_callback_tbl_end_p = {0};
  #endif
#endif

void nvram_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_int32  cb_idx;
    nvram_read_callback_struct *cb_first_entry;
    
#ifdef __MTK_TARGET__
    extern kal_uint32 _nvram_callback_tbl$$Base, _nvram_callback_tbl$$Length;
    cb_idx = (kal_uint32)&_nvram_callback_tbl$$Length/sizeof(nvram_read_callback_struct);
    cb_first_entry = (nvram_read_callback_struct *)&_nvram_callback_tbl$$Base;


#else

    cb_idx = (kal_uint32)(&_nvram_callback_tbl_end_p - &_nvram_callback_tbl_begin_p);
    cb_first_entry = (nvram_read_callback_struct *)&_nvram_callback_tbl_begin_p;

#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (1)
    {
        kal_int32 i = 0;
        /* nvram special service */
        for (;i < cb_idx; i++)
        {
            nvram_read_callback_struct *entry = (nvram_read_callback_struct *)(cb_first_entry + i);
            if (!entry->processed)
            {
                kal_bool result = KAL_TRUE;
                if (entry->callback)
                {
                    result = entry->callback(entry->user_data);
                    entry->processed = KAL_TRUE;
                }

                if (result && entry->module != MOD_NIL && NVRAM_IS_LID_VALID(entry->file_id))
                {
                    {
                        nvram_ltable_entry_struct *ldi;
                        peer_buff_struct *peer_buf_ptr;
                        kal_uint8 *pdu_ptr;
                        kal_uint16 pdu_length;
                        nvram_read_req_struct *local_data;
                        nvram_util_get_data_item(&ldi, entry->file_id);
                    
                        local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
                    
                        local_data->access_id = 0;
                        local_data->file_idx = entry->file_id;
                        local_data->para = 1;
                    
                        pdu_length = ldi->size;
                        peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                    
                        pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
                    
                        nvram_read_confirm(
                            entry->module,
                            nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length),  /* multi-rec read support */
                            local_data,
                            ldi->size,
                            peer_buf_ptr);
                    
                        free_local_para((local_para_struct*) local_data);
                    }
                    
                    entry->processed = KAL_TRUE;
                }
                
            }
        }
        
        msg_receive_extq(&current_ilm);
        kal_set_active_module_id(current_ilm.dest_mod_id);

        nvram_main(&current_ilm);

        destroy_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  nvram_main
 * DESCRIPTION
 *  This is main() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ilm_ptr != NULL);

    if (ilm_ptr != NULL)
    {
        if ((ilm_ptr->msg_id >= MSG_ID_NVRAM_CODE_BEGIN) && (ilm_ptr->msg_id <= MSG_ID_NVRAM_CODE_END))
        {
            if (ilm_ptr->msg_id == MSG_ID_NVRAM_STARTUP_REQ)
            {
                nvram_startup_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_RESET_REQ)
            {
                nvram_reset_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_READ_REQ)
            {
                nvram_read_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_WRITE_REQ)
            {
                nvram_write_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_WRITE_IMEI_REQ)
            {
                nvram_write_imei_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_SET_LOCK_REQ)
            {
                nvram_set_lock_handler(ilm_ptr);
            }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_SUSPEND_REQ)
            {
                nvram_suspend_handler(ilm_ptr);
            }
        #ifdef __NVRAM_BACKUP_DISK_RAW__
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_CREATE_IMAGE_REQ)
            {
                nvram_create_image_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_RECOVER_IMAGE_REQ)
            {
                nvram_recover_image_handler(ilm_ptr);
            }
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_VERIFY_IMAGE_REQ)
            {
                nvram_verify_image_handler(ilm_ptr);
            }
        #endif /* __SYSDRV_BACKUP_DISK_RAW__ */
        #ifdef __NVRAM_SECURE_DATA_STORAGE__
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_SDS_REQ)
            {
                nvram_sds_handler(ilm_ptr);
            }
        #endif
        #if defined(__CCCIFS_SUPPORT__) && defined(__MODEM_CARD__)  // Hosted Dongle Data Card
            else if (ilm_ptr->msg_id == MSG_ID_NVRAM_BIN_REGION_REQ)
            {
                nvram_ap_bin_region_handler(ilm_ptr);
            }
        #endif
        }
    #ifdef TST_HANDLER
        else
        {
            /* not nvram defined message */
            if (ilm_ptr->msg_id == MSG_ID_TST_INJECT_STRING)
            {
                nvram_tst_handler(ilm_ptr);
            }
        }
    #endif /* TST_HANDLER */

    }
}   /* end of module main function */

/*****************************************************************************
 * FUNCTION
 *  nvram_report_conflict_data_item
 * DESCRIPTION
 *
 * PARAMETERS
 *  LID     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_report_conflict_data_item(nvram_lid_enum LID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LIDChanged++;
    /* ASSERT(LIDChanged <= 255); */
    LIDChangeArray[0] = LIDChanged; /* Count */
    LIDChangeArray[LIDChanged] = LID;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_report_sys_data_item
 * DESCRIPTION
 *
 * PARAMETERS
 *  LID     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_report_sys_data_item(nvram_lid_enum LID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LIDChangedSYS++;
    /* ASSERT(LIDChangedSYS <= 255); */
    LIDChangeArraySYS[0] = LIDChangedSYS;   /* Count */
    LIDChangeArraySYS[LIDChangedSYS] = LID;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_create_report_file
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
static kal_bool nvram_create_report_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE handle;
    kal_uint32 filelen = (1 + LIDChanged) * sizeof(kal_uint32);
    kal_uint32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filename, "%s", NVRAM_SWCHANGE_REPORT_FILE);
    FS_Delete(filename);

    handle = FS_Open(filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (handle > FS_NO_ERROR)
    {
        if (FS_Write(handle, LIDChangeArray, filelen, &written) != FS_NO_ERROR)
        {
            FS_Close(handle);
            return KAL_FALSE;
        }
    }
    else
    {
        return KAL_FALSE;
    }

    FS_Close(handle);

    kal_wsprintf(filename, "%s", NVRAM_SWCHANGE_REPORT_FILE_TXT);
    FS_Delete(filename);

    handle = FS_Open(filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (handle > FS_NO_ERROR)
    {
        kal_uint32 index, desc_len;
        kal_char buf[NVRAM_MAX_DESC_LEN + 1];
        nvram_ltable_entry_struct *ldi;

        for (index = LIDChanged; index > 0; index--)
        {
            if (!NVRAM_IS_LID_VALID(LIDChangeArray[index]))
            {
                continue;
            }
            nvram_util_get_data_item(&ldi, LIDChangeArray[index]);

            desc_len = strlen(ldi->description);
            desc_len = (desc_len > NVRAM_MAX_DESC_LEN ? NVRAM_MAX_DESC_LEN : desc_len);

            kal_mem_cpy(buf, ldi->description, desc_len);
            buf[desc_len] = ',';
            if (FS_Write(handle, buf, desc_len + 1, &written) != FS_NO_ERROR)
            {
                FS_Close(handle);
                return KAL_FALSE;
            }
        }
    }
    else
    {
        return KAL_FALSE;
    }

    FS_Close(handle);

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_swchange_warning
 * DESCRIPTION
 *  To warn the user there is no enough space to perform software change.
 * PARAMETERS
 *  SpaceNedded     [IN]
 *  diskversion     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (!defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)) && !defined(EXTERNAL_MMI)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_get_disk_file_info
 * DESCRIPTION
 *  To get infomation of NVRAM FS usage.
 * PARAMETERS
 *  diskfilesize        [OUT]       Total existence file size
 *  freespace           [OUT]       Free space of FS (in byte)
 *  overhead            [OUT]       Overhead space (in byte)
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
kal_bool nvram_get_disk_file_info(kal_uint32 *diskfilesize, kal_uint32 *freespace, kal_uint32 *overhead)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR DriveName[8];
    FS_DiskInfo DI;
    kal_uint32 loop_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(DriveName, "%s\0", "Z:\\");
    if (FS_GetDiskInfo((const WCHAR*)DriveName, &DI, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE) < FS_NO_ERROR)
    {
        return KAL_FALSE;
    }

    /* Set BytesPerCluster to the accurate value */
    BytesPerCluster = DI.BytesPerSector * DI.SectorsPerCluster;

    *freespace = BytesPerCluster * DI.FreeClusters;

    for (*diskfilesize = 0, loop_idx = NVRAM_FOLDER_TOTAL; loop_idx > NVRAM_FOLDER_BEGIN; loop_idx--)
    {
        *diskfilesize += diskSize_of_folder[loop_idx - 1];
    }

    *overhead = BytesPerCluster * OVERHEAD_CLUSTER;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_code_file_size
 * DESCRIPTION
 *  To get infomation of NVRAM RO usage.
 * PARAMETERS
 *  CodeFileSizeTotal       [OUT]       Total RO size
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_get_code_file_size(kal_uint32 *CodeFileSizeTotal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = &logical_data_item_table[0];
    kal_uint32 onefilesize;
#ifdef __NVRAM_PSEUDO_MERGE__
    kal_uint32 package_size = 0;
    kal_uint32 infolid_size = sizeof(head_info_struct);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *CodeFileSizeTotal = 2 * BytesPerCluster * (1 + (NVRAM_EF_SYS_SIZE - 1) / BytesPerCluster);

    do
    {

        /* each record followed by a 2-byte checksum */
        onefilesize = (ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records;

    #ifdef __NVRAM_PSEUDO_MERGE__
        if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
        {
            package_size += onefilesize;
            infolid_size += sizeof(LID_info_struct);
        }
        else
    #endif
        if (NVRAM_IS_CATEGORY_OTP(ldi->category))
        {
            continue;
        }
        else if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr))
        {
            *CodeFileSizeTotal += 2 * BytesPerCluster * (1 + (onefilesize - 1) / BytesPerCluster);
        }
        else
        {
            *CodeFileSizeTotal += BytesPerCluster * (1 + (onefilesize - 1) / BytesPerCluster);
        }
    }while(nvram_util_next_data_item(&ldi));

#ifdef __NVRAM_PSEUDO_MERGE__
    if (package_size)
    {
        *CodeFileSizeTotal += BytesPerCluster * (1 + (package_size - 1) / BytesPerCluster);
        *CodeFileSizeTotal += BytesPerCluster * (1 + (infolid_size - 1) / BytesPerCluster);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  nvram_conflict_resolve_prelim
 * DESCRIPTION
 *  To calc the disk size that software upgrade needs.
 * PARAMETERS
 *  sysrecord       [IN]        Sysrecord
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_conflict_resolve_prelim(kal_uint8 *sysrecord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 diskfilesize, codefilesize, freespace, overhead;
    kal_int32 spaceDelta;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!nvram_get_disk_file_info(&diskfilesize, &freespace, &overhead))
    {
        return KAL_FALSE;
    }

    nvram_get_code_file_size(&codefilesize);

    spaceDelta = codefilesize + overhead - diskfilesize;

    if ((spaceDelta > 0) && (spaceDelta > (kal_int32)freespace))
    {
        //ASSERT(0);
        EXT_ASSERT(0, 0, NVRAM_LOC_SPACE_NOT_ENOUGH, spaceDelta - freespace);
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_destruct_certain_disk_table
 * DESCRIPTION
 *  Free memory pool
 * PARAMETERS
 *  ret     [IN]
 * RETURNS
 *
 *****************************************************************************/
static kal_bool nvram_destruct_disk_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nvram_init_tmp_pool)
    {
        kal_tmp_mem_free(nvram_init_tmp_pool);
        nvram_init_tmp_pool = NULL;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_malloc_disk_table
 * DESCRIPTION
 *  Malloc and construct disk table
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_malloc_disk_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 total_file = 0;
    kal_uint32 folder_idx;

    kal_wchar namepattern[32];
    kal_wchar nvramname[NVRAM_FILE_LEN + 1];
    FS_DOSDirEntry fileinfo;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Step 1: Use FS_FindFist to parse the nvram folder to get the file number and file size */

    for (folder_idx = NVRAM_FOLDER_BEGIN; folder_idx < NVRAM_FOLDER_TOTAL; folder_idx++)
    {
        files_in_folder[folder_idx] = 0;
        diskSize_of_folder[folder_idx] = 0;

        nvram_query_file_name((nvram_folder_enum)folder_idx, "*", namepattern);

        /*
         * 1: Collect disk file count
         * 2: Compute allocate DiskTable
         */
        handle = FS_FindFirst(namepattern, 0, FS_ATTR_DIR, &fileinfo, nvramname, sizeof(nvramname));
        if (handle > 0)
        {
            do
            {
                files_in_folder[folder_idx]++;
                diskSize_of_folder[folder_idx] += BytesPerCluster * (1 + (fileinfo.FileSize - 1) / BytesPerCluster);
            }
            while (FS_FindNext(handle, &fileinfo, nvramname, sizeof(nvramname)) == FS_NO_ERROR);

            FS_FindClose(handle);
        }
        else
        {
            files_in_folder[folder_idx] = 0;
        }

        total_file += files_in_folder[folder_idx];

    }

    /* Step 2: allocate enough memory */
    /* Should revise this place some day. NVRAM should not use kal_tmp_mem_alloc
       And there is a hidden limitation of kal_tmp_mem_alloc.
       kal_tmp_mem_free must be used in pair with kal_tmp_mem_alloc without
       kal_tmp_mem_alloc/kal_sys_mem_alloc in between.
       Therefore, We need to invoke FS_GetDiskInfo in nvram_init one time to avoid this prolem.
       FS_GetDiskInfo -> RTFSYSALLocMutex() -> kal_create_sem -> kal_sys_mem_alloc */

    nvram_init_tmp_pool = (kal_uint32 *)kal_tmp_mem_alloc(sizeof(kal_uint32) * MAX_CHANGE_ARRAY_SIZE * 2 +
                                                           (kal_uint32)(total_file * sizeof(diskTableEntry)));

    LIDChangeArray = nvram_init_tmp_pool;
    LIDChangeArraySYS = nvram_init_tmp_pool + MAX_CHANGE_ARRAY_SIZE;

    if (total_file)
    {
        DiskTable = (diskTableEntry *)(nvram_init_tmp_pool + MAX_CHANGE_ARRAY_SIZE * 2);
        kal_mem_set(DiskTable, 0, total_file * sizeof(diskTableEntry));
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_query_disk_table_addr
 * DESCRIPTION
 *  Get the address of disk table of certain folder
 * PARAMETERS
 *  folder_idx
 * RETURNS
 *  Point of address
 *****************************************************************************/
static diskTableEntry* nvram_query_disk_table_addr(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  loop_idx;
    kal_uint32 file_disk_addr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (loop_idx = folder_idx; loop_idx > 0; loop_idx--)
    {
        file_disk_addr += files_in_folder[loop_idx - 1];
    }

    return (&DiskTable[file_disk_addr]);
}

/*****************************************************************************
 * FUNCTION
 *  nvram_construct_certain_disk_table
 * DESCRIPTION
 *  Construct the files in certain folder to disk table
 * PARAMETERS
 *  folder_idx
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_construct_certain_disk_table(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    FS_DOSDirEntry fileinfo;
    WCHAR namepattern[32];
    WCHAR filename[NVRAM_FILE_LEN + 1];
    kal_uint32 index;
    diskTableEntry *tmp_DiskTable = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_query_file_name(folder_idx, "*", namepattern);

    tmp_DiskTable = nvram_query_disk_table_addr(folder_idx);

    handle = FS_FindFirst(namepattern, 0, FS_ATTR_DIR, &fileinfo, filename, sizeof(filename));
    if (handle > 0)
    {
        index = 0;
        do
        {
            if (index >= files_in_folder[folder_idx]) /* entry numbers mismatch .... error out */
            {
                return KAL_FALSE;
            }

            kal_wstrncpy(tmp_DiskTable[index].diskfile, filename, NVRAM_FILE_LEN);
            //at nvram_util_make_filename()£¬it uses '\0' as the end char
			//at here it should use same char as end, otherwise lid will be reset
			//as registed in LIDChangeArray[] when modem version changed
            tmp_DiskTable[index].diskfile[NVRAM_FILE_LEN] = '\0';  /* Terminator */
            index++;
        }
        while (FS_FindNext(handle, &fileinfo, filename, sizeof(filename)) == FS_NO_ERROR);
    }
    else
    {
        if (files_in_folder[folder_idx] != 0)
        {
            return KAL_FALSE;
        }
        else
        {
            return KAL_TRUE;
        }
    }

    FS_FindClose(handle);

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_construct_disk_table
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
static kal_bool nvram_construct_disk_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 loop_idx;
    kal_bool  ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!nvram_malloc_disk_table())
    {
        return KAL_FALSE;
    }

    for (loop_idx = NVRAM_FOLDER_TOTAL; loop_idx > NVRAM_FOLDER_BEGIN ; loop_idx--)
    {
        ret = nvram_construct_certain_disk_table((nvram_folder_enum)(loop_idx - 1));

        if (!ret)
        {
            nvram_destruct_disk_table();
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_search_disk_table
 * DESCRIPTION
 *  Search certain file whether in disk table or not
 * PARAMETERS
 *  name        : [In]  file name
 *  folder_idx  : [In]  which folder
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_search_disk_table(char *name, nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    diskTableEntry *dfile;
    kal_uint32 index;
    kal_uint32 lop_start = 0;
    kal_uint32 lop_end = 0;
    WCHAR filename[NVRAM_FILE_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* translate name into 2-byte format
     * because file names in Disk table are in 2-byte format
     */
    kal_wsprintf(filename, "%s", name);

    if (folder_idx == 0)
    {
        lop_start = 0;
    }
    else /* folder_idx == 1 */
    {
        for (index = 0; index < folder_idx; index++)
        {
            lop_start += files_in_folder[index];
        }
    }

    lop_end = lop_start + files_in_folder[folder_idx];

    for (index = lop_start; index < lop_end; index++)
    {
        dfile = &(DiskTable[index]);

        if (!dfile->checked)
        {
            if (!kal_wstrcmp(dfile->diskfile, filename))
            {
                dfile->checked = KAL_TRUE;  /* mark this file is in the Disk table */
                return KAL_TRUE;
            }
        }
    }

    return KAL_FALSE;
}

#if !defined(__CCCIFS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  nvram_delete_certain_disk_files_unchecked
 * DESCRIPTION
 *  Delete all file unchecked in certain folder
 * PARAMETERS
 *  folder_idx : [in]
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_delete_certain_disk_files_unchecked(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    diskTableEntry *dfile;
    kal_uint32 index;
    kal_uint32 lop_start = 0;
    kal_uint32 lop_end = 0;

    WCHAR filename[NVRAM_MAX_PATH_LEN];

#ifdef __NVRAM_PSEUDO_MERGE__
    WCHAR package_name[NVRAM_FILE_LEN + 1];
    NVRAM_FILE_NAME nvramname;
    WCHAR information_name[NVRAM_FILE_LEN + 1];
    /* NVRAM_FILE_NAME inforname; */
#endif /* __NVRAM_PSEUDO_MERGE__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_PSEUDO_MERGE__
    nvram_make_package_filename(nvramname, 'A');
    kal_wsprintf(package_name, "%s", nvramname);

    nvram_make_package_info_filename(nvramname, 'A');
    kal_wsprintf(information_name, "%s", nvramname);
#endif /* __NVRAM_PSEUDO_MERGE__ */

    if (folder_idx == 0)
    {
        lop_start = 0;
    }
    else /* folder_idx == 1 */
    {
        for (index = 0; index < folder_idx; index++)
        {
            lop_start += files_in_folder[index];
        }
    }

    lop_end = lop_start + files_in_folder[folder_idx];

    for (index = lop_start; index < lop_end; index++)
    {
        dfile = &(DiskTable[index]);

        if (!dfile->checked)
        {
            dfile->checked = KAL_TRUE;  /* mark this file in the Disk table. does this matter? */

        #ifdef __NVRAM_PSEUDO_MERGE__   /* Prevent to delete Package file */
            if (folder_idx == 0)
            {
                /* If diskfile == package file, break the loop, do not del */
                if (!kal_wstrcmp(dfile->diskfile, package_name))
                {
                    continue;
                }
                /* If diskfile == information file, break the loop, do not del */
                if (!kal_wstrcmp(dfile->diskfile, information_name))
                {
                    continue;
                }
            }
        #endif /* __NVRAM_PSEUDO_MERGE__ */

            //kal_wsprintf(filename, "%s\\%w\0", NVRAM_FS_DATAITEM_PATH, dfile->diskfile);
            nvram_query_ex_file_name(folder_idx, dfile->diskfile, filename);
            if (FS_Delete(filename) != FS_NO_ERROR)
            {
                return KAL_FALSE;
            }
        }
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_delete_disk_files_unchecked
 * DESCRIPTION
 *  Delete all file unchecked
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_delete_disk_files_unchecked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 loop_idx;
    kal_bool  ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (loop_idx = NVRAM_FOLDER_TOTAL; loop_idx > NVRAM_FOLDER_BEGIN; loop_idx--)
    {
        ret = nvram_delete_certain_disk_files_unchecked((nvram_folder_enum)(loop_idx - 1));

        if (!ret)
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_version_conflict_resolve
 * DESCRIPTION
 *  To perform software upgrade.
 * PARAMETERS
 *  sysrecord       [IN]        Sysrecord
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_version_conflict_resolve(kal_uint8 *sysrecord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi;
    kal_uint32 file_idx;
    kal_uint32 index;
    NVRAM_FILE_NAME nvramname1, nvramname2;
    nvram_folder_enum folder_index1, folder_index2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*****************************************************
        * Launch power first and show the first picture
        ******************************************************/
    nvram_util_poweron();
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    MMICheckDiskDisplay();
#endif


    if (!nvram_construct_disk_table())
    {
        return KAL_FALSE;
    }

    if (!nvram_conflict_resolve_prelim(sysrecord))
    {
        return nvram_destruct_disk_table();
    }

    LIDChangeArray[0] = 0;  /* Count */
    LIDChanged = 0;

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_VERSION_CONFLICT_RESOLVE, 0);
    /****** 1st phase for loop starts here. The looping is based on the Code table ******/
    ldi = &logical_data_item_table[0];
    do
    {
        /* those data items need to be reset to code default values */
        if (ldi->attr & NVRAM_ATTR_SW_VERNO_RESET)
        {
            nvram_report_sys_data_item(ldi->LID);
        }
        else
        {
            folder_index1 = nvram_query_folder_index_ex(ldi->category, KAL_TRUE);
            folder_index2 = nvram_query_folder_index_ex(ldi->category, KAL_FALSE);

        #ifdef __NVRAM_PSEUDO_MERGE__
            if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
            {
                continue;   /* this function will not deal with package lid */
            }
            else
        #endif
            if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr)) /* Process Multiple */
            {
                nvram_util_make_lid_filename(ldi, nvramname1, KAL_TRUE);
                nvram_util_make_lid_filename(ldi, nvramname2, KAL_FALSE);

                /* Both file must exist */
                if (!nvram_search_disk_table(nvramname1, folder_index1) ||
                    !nvram_search_disk_table(nvramname2, folder_index2))
                {
                    /* report the data item */
                    nvram_report_conflict_data_item(ldi->LID);
                }
            }
            else    /* Process Single */
            {
                /* construct filename */
                nvram_util_make_lid_filename(ldi, nvramname1, KAL_TRUE);

                if (!nvram_search_disk_table(nvramname1, folder_index1))
                {
                    /* report the data item */
                    nvram_report_conflict_data_item(ldi->LID);
                }
            }
        }
    }while(nvram_util_next_data_item(&ldi));

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_VERSION_CONFLICT_RESOLVE, 1);
    /****** 1st phase for loop ends here ******/

    nvram_create_report_file();

    /* remove all files left unchecked in Disk table */
    
    // [Smart Phone Modem][Telephony Load Reduction] Keep all files
    #if !defined(__CCCIFS_SUPPORT__)
    if (!nvram_delete_disk_files_unchecked())
    {
        return nvram_destruct_disk_table();
    }
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_VERSION_CONFLICT_RESOLVE, 2);
    #endif

    /****** 2nd phase for loop starts here. The looping is based on LIDChangeArray ******/
    for (index = 1; index <= LIDChanged; index++)
    {
        file_idx = LIDChangeArray[index];

        nvram_util_get_data_item(&ldi, file_idx);

        if (!ldi)
        {
            continue;
        }


    #ifdef __NVRAM_BACKUP_DISK__
        if (NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr) || NVRAM_IS_ATTR_BACKUP_RAW(ldi->attr))
        {
            if (nvram_recover_image_by_lid(ldi) == NVRAM_ERRNO_SUCCESS)
            {
                continue;
            }
        }
    #endif

        if (!nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records))
        {
            return nvram_destruct_disk_table();
        }

    }

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_VERSION_CONFLICT_RESOLVE, 3);
    /* those data items need to be reset to code default values */
    for (index = 1; index <= LIDChangedSYS; index++)
    {
        file_idx = LIDChangeArraySYS[index];

        nvram_util_get_data_item(&ldi, file_idx);

        if (!ldi)
        {
            continue;
        }

        if (!nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records))
        {
            return nvram_destruct_disk_table();
        }
    }
   /****** 2nd phase for loop ends here ******/

   nvram_trace(TRACE_FUNC, FUNC_NVRAM_VERSION_CONFLICT_RESOLVE, 4);
    /****** rewrite system records ******/
    nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_LID);
    if (!nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, 1))
    {
        return nvram_destruct_disk_table();
    }

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_VERSION_CONFLICT_RESOLVE, 5);
    return nvram_destruct_disk_table();
}

/*****************************************************************************
 * FUNCTION
 *  nvram_decrypt_lock_state
 * DESCRIPTION
 *  Set lock state to nvram context.
 * PARAMETERS
 *  coded_version       [IN]        Pointer to address of version/lock pattern.
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool nvram_decrypt_lock_state(kal_uint8 *coded_version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 lock_pattern[NVRAM_EF_SYS_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_cpy(lock_pattern, coded_version + CODED_LOCK_PATTERN_OFFSET, NVRAM_EF_SYS_SIZE);

    custom_nvram_decrypt(nvram_ptr->secret_key, lock_pattern, CODED_LOCK_PATTERN_SIZE, 0);

    /* Compare the lock pattern to set current lock status */
    if (kal_mem_cmp(lock_pattern, NVRAM_LOCK_PATTERN_LOCKED, CODED_LOCK_PATTERN_SIZE) == 0)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  nvram_write_system_record
 * DESCRIPTION
 *  This function is used to write system record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

kal_bool nvram_write_system_record(nvram_lock_state_enum lock_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool write_status = KAL_FALSE;
    nvram_ltable_entry_struct *ldi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (lock_state == NVRAM_LOCK_DISABLE)
    {
        nvram_ptr->lock = KAL_FALSE;
    }
    else if (lock_state == NVRAM_LOCK_ENABLE)
    {
        nvram_ptr->lock = KAL_TRUE;
    }
    else
    {
        /* use default value assigned by custom */
        nvram_ptr->lock = nvram_custom_lock_status();
    }

    nvram_assign_system_record_default_value((kal_char *)nvram_ptr->coded_version, release_verno(), nvram_ptr->lock);

    nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_LID);

    if (nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records))
    {
        write_status = KAL_TRUE;
    }

    /* Fatal error. Cannot write system-level record!? */
//    EXT_ASSERT(write_status == KAL_TRUE, NVRAM_EF_SYS_LID, __LINE__, 0);
    EXT_ASSERT(write_status == KAL_TRUE, 0, NVRAM_LOC_WRITE_SYS_LID_FAIL, nvram_ptr->state);

//    nvram_lock_all_file(nvram_ptr->lock);

    return write_status;
}



/*****************************************************************************
 * FUNCTION
 *  nvram_supplementary_check_data_item
 * DESCRIPTION
 *  do some supplementary check, such as branch or customer package
 * PARAMETERS
 *  LIDtoCheck      [IN]        Should be the record to check
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool nvram_supplementary_check_data_item(nvram_lid_enum LIDtoCheck)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi;
    kal_bool result = KAL_FALSE;
    kal_uint16 rec_id = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    switch(LIDtoCheck)
    {
        case NVRAM_EF_SYS_LID:
            nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_LID);
            rec_id = 1;
            break;
        case NVRAM_EF_BRANCH_VERNO_LID:
            nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_LID);
            rec_id = 2;
            break;
        case NVRAM_EF_FLAVOR_VERNO_LID:
            nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_LID);
            rec_id = 3;
            break;
        default:
            nvram_util_get_data_item(&ldi, LIDtoCheck);
            break;
    }
    
    {
        kal_uint8 *buffer = (kal_uint8*) get_ctrl_buffer(ldi->size);

        if (nvram_read_data_item(ldi, rec_id, 1, buffer, ldi->size) == NVRAM_IO_ERRNO_OK)
        {
            kal_uint8 *default_value = (kal_uint8*) get_ctrl_buffer(ldi->size);    
            
            nvram_get_default_value_to_write(ldi, rec_id, default_value, ldi->size);
            
            if (kal_mem_cmp((kal_char*) buffer, (kal_char*) default_value, ldi->size) != 0)
            {
                result = KAL_FALSE;
            }
            else
            {
                result = KAL_TRUE;
            }
            free_ctrl_buffer(default_value);
        }
        else
        {
            result = KAL_FALSE;
        }
        free_ctrl_buffer(buffer);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_supplementary_check
 * DESCRIPTION
 *  do some supplementary check, such as branch or customer package
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool nvram_supplementary_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool temp_result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Step 1: handle branch(flavor)/BIN change */
    /* branch and flavor must all same with before, or else reset branch */
    if ((!nvram_supplementary_check_data_item(NVRAM_EF_BRANCH_VERNO_LID))
        || (!nvram_supplementary_check_data_item(NVRAM_EF_FLAVOR_VERNO_LID)))
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_SUPPLEMENTARY_CHECK, 0);
    #if defined(__CCCIFS_SUPPORT__)
        // [Smart Phone Modem][Telephony Load Reduction] && [Data Card][RNDIS/HOSTED Dongle]
        // Skip flavor checks, because of LID sharing between modems.
    #else
        temp_result = nvram_reset_data_items(NVRAM_RESET_BRANCH, NVRAM_APP_RESERVED, NULL, 0, 0);
    #endif
        nvram_ptr->sw_status |= NVRAM_SW_BRANCH_CHANGE;
    }

#ifdef __NVRAM_SUPPORT_CUSTPACK__
    /* Step 2: handle custpack change */
    if (!nvram_supplementary_check_data_item(NVRAM_EF_CUSTPACK_VERNO_LID))
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_SUPPLEMENTARY_CHECK, 1);
        temp_result = nvram_reset_data_items(NVRAM_RESET_CUSTPACK, NVRAM_APP_RESERVED, NULL, 0, 0);
        nvram_ptr->sw_status |= NVRAM_SW_CUSTPACK_CHANGE;
    }
#endif

#ifdef __SECURE_RO_ENABLE__    
    /* Step 3: handle secupack change */
    if (!nvram_supplementary_check_data_item(NVRAM_EF_SECUPACK_VERNO_LID))
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_SUPPLEMENTARY_CHECK, 2);
        temp_result = nvram_reset_data_items(NVRAM_RESET_SECUPACK, NVRAM_APP_RESERVED, NULL, 0, 0);
        nvram_ptr->sw_status |= NVRAM_SW_SECUPACK_CHANGE;
    }
#endif
    return temp_result;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_init_all_ldi
 * DESCRIPTION
 *  Formats device by invoking drv_format() function. Re-initialize all logical data items to
 *  default value.
 *
 *  This function is supposed to be called only when:
 *  1> unformatted device.
 *  2> system level record read error.
 *  3> incompatible version.
 * PARAMETERS
 *  reset_category          [IN]
 *  is_after_format(?)      [IN]        Only when device is just re-formatted will this value be true.
 * RETURNS
 *  Result of writing system records. KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
static kal_bool nvram_init_all_ldi(nvram_reset_category_enum reset_category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*****************************************************
        * Launch power first and show the first picture
        ******************************************************/
    nvram_util_poweron();
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    MMICheckDiskDisplay();
#endif

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
	bResetNvramData = KAL_TRUE;
#endif

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT_ALL, reset_category);
    reset_category = NVRAM_RESET_ALL;
    if (reset_category == NVRAM_RESET_ALL)
    {
        if (nvram_ptr->sw_status & NVRAM_SW_EMPTY_FAT)
        {
            nvram_delete_all_nvram_files(NVRAM_FIRST_BOOTUP);
        }
        else
        {
            nvram_delete_all_nvram_files(NVRAM_NORMAL_BOOTUP);
        }
    }

    nvram_reset_data_items(reset_category, NVRAM_APP_RESERVED, NULL, 0, 0);
    nvram_write_system_record((nvram_lock_state_enum)nvram_ptr->lock);

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_scan_all_ldi
 * DESCRIPTION
 *  Scan all data item and compare the files to make sure the files is vaild
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
/*
 * Changdou....
 * scan certain folder
 */
static void nvram_scan_all_ldi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_FileOpenHint Hint;
    NVRAM_FILE_NAME nvramname;
    kal_int32 file_size = 0;
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    nvram_folder_enum folder_index;
    kal_uint32 i;
    nvram_ltable_entry_struct *ldi = &logical_data_item_table[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Must clear up Hint beforehand */
    memset(&Hint, 0, sizeof(Hint));

    do
    {

    #ifdef __NVRAM_PSEUDO_MERGE__
        if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
        {
            continue;
        }
    #endif

        // we do not delete the important file here
        if (NVRAM_IS_CATEGORY_IMPORTANT(ldi->category) || NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category))
        {
            continue;
        }

        // We only handle the file size > 0 but not match ex: some app forget to increase the verno
        // Because if the file size = 0, nvram will recover it when app try to read it
        // IF the file with multiple attribute, we should check the both file size

        for (i = 0 ; i < 2; i++)
        {
            kal_uint32 section_size;

            folder_index = nvram_query_folder_index(ldi->category);

            if (i == 0)  // first copy
            {
                nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);
            }
            else // second copy
            {
                nvram_util_make_lid_filename(ldi, nvramname, KAL_FALSE);

            #ifdef __NVRAM_BACKUP_DISK_FAT__
                if (NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
                {
                    folder_index = NVRAM_NVD_BAK;
                }
            #endif
            }

            file_size = nvram_drv_fat_get_record_size(nvramname, &Hint, folder_index);

        #if defined(__CCCIFS_SUPPORT__)
            /* the calibration data is existed and it is corruptted */
            if (folder_index == NVRAM_NVD_CALI && file_size > 0 && file_size != (kal_int32)((ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records))
            {
                //EXT_ASSERT(KAL_FALSE, ldi->LID, file_size, (ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records);
                EXT_ASSERT(KAL_FALSE, LID_OWNER_ERR(ldi->LID), NVRAM_LOC_CALIBRATION_SIZE_CHANGE, file_size);

            }
        #endif


            if (ldi->attr & NVRAM_ATTR_MSP)
            {
                section_size = NVRAM_MSP_ALIGNMENT_CEILING(ldi->size + NVRAM_CHKSUM_SIZE);
            }
            else
            {
                section_size = ldi->size + NVRAM_CHKSUM_SIZE;
            }


            if (file_size > 0 && file_size != (kal_int32)(section_size * ldi->total_records))
            {
                nvram_query_file_name(folder_index, nvramname, filename);
                FS_Delete(filename);
            }

            /* for compressed item, nvram need to reset it at init stage */
        #ifdef __NVRAM_COMPRESS_SUPPORT__
            if (NVRAM_IS_ATTR_ZIP_DEFAULT(ldi->attr) && file_size != (kal_int32)(section_size * ldi->total_records))
            {
                nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records);
            }
        #endif /* __NVRAM_COMPRESS_SUPPORT__ */

            if (!NVRAM_IS_ATTR_MULTIPLE(ldi->attr))
            {
                break;
            }
        }

    }while(nvram_util_next_data_item(&ldi));
}


/*****************************************************************************
 * FUNCTION
 *  nvram_test_lock
 * DESCRIPTION
 *  get lock state from nvram context.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE if locked, else KAL_FALSE
 *****************************************************************************/
kal_bool nvram_test_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nvram_ptr->lock;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_init
 * DESCRIPTION
 *  This is init() function of NVRAM module.
 *  This function initialize all the context variables required for NVRAM module
 * PARAMETERS
 *  task_indx       [IN]
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
kal_bool nvram_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ld_init_result = KAL_TRUE;
    nvram_drv_status_enum drv_init_result = NVRAM_ERRNO_SUCCESS;
    nvram_ltable_entry_struct *ldi = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Assume that BytesPerCluster still not initialized if BytesPerCluster==0 */

    if (BytesPerCluster == 0)
    {
        /* Please do not remove this code if NVRAM still use kal_tmp_mem_alloc
           The detail reason please see nvram_malloc_disk_table */
        FS_DiskInfo DI;
        FS_GetDiskInfo((const WCHAR*)L"Z:\\", &DI, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        /* Set BytesPerCluster to the accurate value */
        BytesPerCluster = DI.BytesPerSector * DI.SectorsPerCluster;
    }

    g_nvram_imei_mutex = kal_create_mutex("NVIMEI");

    nvram_ptr->sw_status = 0;

    /*****************************************************
     * Construct NVRAM table and init some default value
     ******************************************************/
    nvram_pre_init();


#ifdef __NVRAM_BACKUP_DISK__
    /*****************************************
     * Init Backup partition
     *********************************************/
    nvram_init_backup_disk();
#endif


#ifdef __NVRAM_SECURE_DATA_STORAGE__
    /****************************************************
     * Init Secure Data Storage and get the storage mode
     ******************************************************/
    if (nvram_sds_status() == NVRAM_ERRNO_SDS_EMPTY)
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 0, 0);
        nvram_ptr->sw_status |= NVRAM_SW_EMPTY_SDS;
        nvram_sds_init_start();
        //nvram_init_all_ldi(NVRAM_RESET_SDS);
        nvram_sds_init_end();
    }
#endif

    /*****************************************
     * Init FAT
     *  if the secure storage is empty => software version ... and many data is missing
     *  => format all
     *********************************************/

    if ((drv_init_result = nvram_drv_fat_status()) == NVRAM_DRV_UNFORMATTED)
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 1, 0);
        nvram_ptr->sw_status |= NVRAM_SW_EMPTY_FAT;
        nvram_drv_fat_init_start();
        nvram_init_all_ldi(NVRAM_RESET_ALL);
        nvram_drv_fat_init_end();
    }
    else if (drv_init_result == NVRAM_DRV_FOLDER_NOT_READY)
    {
        nvram_create_all_folder();
    }
    else if (drv_init_result == NVRAM_DRV_DRIVE_BROKEN || drv_init_result == NVRAM_DRV_DRIVE_VNOERR)
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 2, 0);
        nvram_ptr->dev_broken = KAL_TRUE;
		goto INIT_END;
    }

    /*****************************************
     * Init OTP
     *********************************************/
#ifdef __NVRAM_OTP__
    nvram_otp_construct();
#endif

    /*****************************************
     * Check system record and do version compatible
     *********************************************/
    if ((nvram_ptr->sw_status & NVRAM_SW_EMPTY_FAT)
    #ifdef __NVRAM_SECURE_DATA_STORAGE__
        && (nvram_ptr->sw_status & NVRAM_SW_EMPTY_SDS)
    #endif
        )
    {

        nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 3, 0);
        goto INIT_END;
    }



    /* Read back system-level record to retrieve software-lock status and data version
     *
     * 1. Read failed:
     *        NVRAM Layer must re-initialize all logical data items
     *            b'coz we could not ensure the healthy of all ldi, and return.
     * 2. Read success but incompatible versions:
     *        Step 1: NVRAM Layer must re-initialize all 'USER' category logical data items.
     *        Step 2: According the result of step 1, jump step 3 or step 4
     *        Step 3: Step 1 is success, Must assue following version don't re-initialize in step 1.
     *             3.1 check branch version
     *             3.2 check flavor version
     *             3.3 check custpack version
     *             3.4 check secupack version
     *        Step 4: Step 1 is fail
     *             4.1 Initial all data item
     * 3. Read success and compatible versions:
     *        3.1 check branch version
     *        3.2 check flavor version
     *        3.3 check custpack version
     *        3.4 check secupack version
     */

    kal_mem_set(nvram_ptr->old_coded_version, 0, NVRAM_EF_SYS_SIZE + 1);
    nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_LID);
    if (nvram_read_data_item(ldi, 1, 1, nvram_ptr->old_coded_version, NVRAM_EF_SYS_SIZE) != NVRAM_IO_ERRNO_OK)
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 5, 0);
    
    #ifndef __NVRAM_MULTI_FOLDERS__
        nvram_ptr->sw_status |= NVRAM_SW_EMPTY_FAT;
    #else
        nvram_ptr->sw_status |= NVRAM_SW_VERSION_CHANGE;
    #endif
        nvram_init_all_ldi(NVRAM_RESET_FAT);
    }
#if defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__)
    else if (ccci_queryBootAttributes(BOOT_ATTR_IS_CLEAN_BOOT))
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 6, 0);
    
        nvram_init_all_ldi(NVRAM_RESET_FAT);
    }
#endif
    else
    {


    /* Initial pseudo merge first */
    #ifdef __NVRAM_PSEUDO_MERGE__
        if (!nvram_pseudo_merge())
        {
            FS_Delete(L"z:\\NVRAM\\NVD_DATA\\INFOALID");
            FS_Delete(L"z:\\NVRAM\\NVD_DATA\\PACKALID");
            nvram_pseudo_merge();
        }
    #endif

        /* maintain the lock status even after software upgrade */

        nvram_ptr->lock = nvram_decrypt_lock_state(nvram_ptr->old_coded_version);

        nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 7, nvram_ptr->lock);
        nvram_assign_system_record_default_value((kal_char *)nvram_ptr->coded_version, release_verno(), nvram_ptr->lock);

        /*
         * Read system record success, Compare code version first
         */
        if (strncmp((kal_char*) nvram_ptr->old_coded_version, (kal_char*) nvram_ptr->coded_version, CODED_DATA_VERSION_SIZE) != 0)
        {
            nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 8, 0);
        
            nvram_ptr->sw_status |= NVRAM_SW_VERSION_CHANGE;

            /* Re_initial user data in version_conflict resolve */
            ld_init_result = nvram_version_conflict_resolve(nvram_ptr->old_coded_version);

            if (ld_init_result)
            {
                nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 9, 0);
                ld_init_result = nvram_supplementary_check();
                nvram_scan_all_ldi();
            }
            else
            {
                nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 10, 0);
            
                /* if errors happen during conflict resolution, initialize all LIDs */
                {
                    ld_init_result = nvram_init_all_ldi(NVRAM_RESET_ALL);
                }
            }

            /* switch the mode back to SDS mode if need */

        }
        else    /* version compatible */
        {
            /*
             * Read sys record success and version compatible
             * This case means handset is power on normally:
             * So, nvram should only query restore factory in this case
             */
            nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 12, 0);
        
            ld_init_result = nvram_supplementary_check();

            nvram_scan_all_ldi();

            if ((ld_init_result == KAL_TRUE) && nvram_check_restore_factory_flag())
            {
                nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 13, 0);
                nvram_reset_data_items(NVRAM_RESET_FACTORY, NVRAM_APP_RESERVED, 0, 0, 0);
            }

        }   /* version compatible */

//        nvram_lock_all_file(nvram_ptr->lock);
    }

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_INIT, 14, 0);

INIT_END:

    nvram_ptr->state = NVRAM_STATE_READY;

    custom_em_nvram_config_com_port();
    custom_nvram_config();

#if !defined(L4_NOT_PRESENT)
    /* load SBP file */
    {
        nvram_external_read_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
                                 1, 
                                 (kal_uint8*)&sbp_config, 
                                 NVRAM_EF_SBP_MODEM_CONFIG_SIZE);
        
        nvram_external_read_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                 1, 
                                 (kal_uint8*)&sbp_data_config, 
                                 NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);
    }
#endif

    return KAL_TRUE;
}   /* end of nvram_init function */

/*****************************************************************************
 * FUNCTION
 *  nvram_reset
 * DESCRIPTION
 *  This is reset() function of NVRAM module.
 * PARAMETERS
 *  task_indx       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool nvram_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__)
    nvram_ptr->state = NVRAM_STATE_NULL;
#endif
    return KAL_TRUE;
}   /* end of nvram_reset function */



/*****************************************************************************
 * FUNCTION
 *  nvram_report_last_exception
 * DESCRIPTION
 *
 * PARAMETERS
 *  task_name_p     [?]
 *  type_p          [?]
 *  time_p          [?]
 *  status_p        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_report_last_exception(void *task_name_p, void *type_p, void *time_p, void *status_p)
{
}  

/*****************************************************************************
 * FUNCTION
 *  nvram_create_first_bootup_name
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_create_first_bootup_name(kal_char *prefix, kal_wchar* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *working_buffer = (kal_char*) get_ctrl_buffer(32);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(working_buffer, 0, 32);
    strncpy(working_buffer, release_verno(), 32);
#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    SST_Secure_Algo(NVRAM_MSP_ENCRYPT, (kal_uint32)working_buffer, 32, nvram_ptr->secret_key, (kal_uint8*)working_buffer);
#else
    custom_nvram_encrypt(nvram_ptr->secret_key, (unsigned char *)working_buffer, 32, 0);
#endif
    kal_wsprintf(filename, "Z:\\%s%02X%02X%02X%02X.log", prefix, working_buffer[4], working_buffer[5], working_buffer[6], working_buffer[7]);

    free_ctrl_buffer(working_buffer);
}

/*****************************************************************************
 * FUNCTION
 *  nvram_create_first_bootup_file
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_create_first_bootup_log(kal_char *prefix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_create_first_bootup_name(prefix, filename);

    FS_Close(FS_Open(filename, FS_READ_WRITE | FS_CREATE_ALWAYS));
}

/*****************************************************************************
 * FUNCTION
 *  nvram_check_first_bootup_log
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool nvram_check_first_bootup_log(kal_char *prefix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_create_first_bootup_name(prefix, filename);

    if (FS_GetAttributes(filename) >= FS_NO_ERROR)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  nvram_delete_first_bootup_log
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_delete_first_bootup_log(kal_char *prefix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_create_first_bootup_name(prefix, filename);
    FS_Delete(filename);
}

#ifdef __NVRAM_SECURE_DATA_STORAGE__

/*****************************************************************************
 * FUNCTION
 *  nvram_access_sds
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_int32 nvram_access_sds(nvram_sds_access_enum access_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    nvram_errno_enum result = NVRAM_ERRNO_SUCCESS;

    if (access_mode == NVRAM_SDS_ACCESS_BACKUP)
    {
        result = nvram_sds_backup();
    }
    else
    {
        result = nvram_sds_restore();
    }

    
    return result;
}
#endif
