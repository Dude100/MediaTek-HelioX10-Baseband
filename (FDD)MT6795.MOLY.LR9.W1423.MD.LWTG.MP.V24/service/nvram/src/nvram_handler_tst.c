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
 * nvram_handler_tst.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is tst handler function of NVRAM module.
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
 *============================================================================
 ****************************************************************************/
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"   /* kal_internal_hisrid */
#include "kal_trace.h"
#include "nvram_msgid.h"

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"

#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "nvram_main.h"

#include "tst_sap.h"

/* Exception */
#include "ex_item.h"

/* Statistics */
#include "ctrl_buff_pool.h"
#include "sysconf_statistics.h"

#include "task_config.h"

extern task_info_struct *task_info_g;
extern kal_internal_hisrid kal_hisr_ptrs_g[KAL_MAX_NUM_HISRS];
extern kal_uint32 KALTotalTasks;


/*****************************************************************************
 * FUNCTION
 *  nvram_tst_handler
 * DESCRIPTION
 *  This is nvram_tst_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_tst_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_TST);

    ASSERT(tst_inject != NULL);

    if (!nvram_ptr->dev_broken && nvram_ptr->state == NVRAM_STATE_READY)
    {

    #ifdef __NVRAM_OTP__
        if (strcmp((kal_char*) tst_inject->string, "otp_start")==0)
        {
            extern kal_uint32 nvram_otp_size;
            extern void nvram_otp_construct(void);
            nvram_otp_size = tst_inject->index * 10;
            nvram_otp_construct();
        }
        else
    #endif /* __NVRAM_OTP__ */
        if (strcmp((kal_char*) tst_inject->string, "ex_reset") == 0)
        {
            nvram_ltable_entry_struct *ldi;

            nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_EXCEPTION_LID);

            if (nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE)
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_OK);
            }
            else
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_FAIL);
            }
        }
        else if (strcmp((kal_char*) tst_inject->string, "ex_fetch") == 0)
        {
            kal_uint8 i;
            nvram_ltable_entry_struct *ldi;
            peer_buff_struct *peer_buf_ptr;
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;
            nvram_read_req_struct *local_data;
            nvram_errno_enum ret;

            nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_EXCEPTION_LID);

            if ((kal_uint8*) tst_inject->index == 0)
            {
                /* Get ALL Exception Records */
                for (i = 1; i <= NVRAM_EF_SYS_EXCEPTION_TOTAL; i++)
                {
                    local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
                    local_data->access_id = 0;
                    local_data->file_idx = (NVRAM_EF_SYS_EXCEPTION_LID);
                    local_data->para = i;

                    pdu_length = ldi->size;
                    peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                    pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);

                    ret = nvram_read_data_item(ldi, i, 1, pdu_ptr, pdu_length); /* multi-rec read support */

                    if (((EX_LOG_T*) pdu_ptr)->header.ex_nvram == 0xFF)
                    {
                        nvram_trace(TRACE_FUNC, TEST_VALID_EXCEPTIONS, (i - 1));
                        free_peer_buff(peer_buf_ptr);
                        free_local_para((struct local_para_struct*)local_data);

                        break;
                    }

                    nvram_read_confirm(MOD_NVRAM, ret, local_data, ldi->size, peer_buf_ptr);

                }

            }
            else if ((kal_uint8) tst_inject->index <= NVRAM_EF_SYS_EXCEPTION_TOTAL)
            {
                /* Get Certain Exception Records */
                local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
                local_data->access_id = 0;
                local_data->file_idx = (NVRAM_EF_SYS_EXCEPTION_LID);
                local_data->para = (kal_uint8) tst_inject->index;

                pdu_length = ldi->size;
                peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);

                ret = nvram_read_data_item(ldi, (kal_uint8) tst_inject->index, 1, pdu_ptr, pdu_length); /* multi-rec read support */
                if (((EX_LOG_T*) pdu_ptr)->header.ex_nvram == 0xFF)
                {
                    nvram_trace(TRACE_FUNC, TEST_INVALID_EXCEPTIONS, tst_inject->index);
                    free_peer_buff(peer_buf_ptr);
                    free_local_para((struct local_para_struct*)local_data);
                }
                else
                {

                    nvram_read_confirm(MOD_NVRAM, ret, local_data, ldi->size, peer_buf_ptr);
                }

            }
            else
            {
                nvram_trace(TRACE_FUNC, TEST_REC_NUM_OUT_RANGE);
            }
        }
        else if (strcmp((kal_char*) tst_inject->string, "stat_checked") == 0)
        {
            nvram_ltable_entry_struct *ldi;
            stack_statistics_struct *stat_ptr;
            nvram_errno_enum ret;

            /* Dynamically allocates buffer, otherwise stack could overflow. */
            stat_ptr = (stack_statistics_struct*) get_ctrl_buffer(NVRAM_EF_SYS_STATISTICS_SIZE);

            nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_STATISTICS_LID);

            /* Read statistaics data item */
            ret = nvram_read_data_item(ldi, 1, 1, (kal_uint8*) stat_ptr, NVRAM_EF_SYS_STATISTICS_SIZE);        /* multi-rec read support */
            if ((ret == NVRAM_IO_ERRNO_OK) || (ret == NVRAM_IO_ERRNO_INIT))
            {
                stat_ptr->stack_stats_status = STACK_STATS_NONE;
                nvram_write_data_item(ldi, 1, (kal_uint8*) stat_ptr, KAL_FALSE);
            }

            free_ctrl_buffer(stat_ptr);
        }
        else if (strcmp((kal_char*) tst_inject->string, "stat_reset") == 0)
        {
            nvram_ltable_entry_struct *ldi;

            nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_EXCEPTION_LID);

            if (nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE)
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_STAT_OK);
            }
            else
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_STAT_FAIL);
            }
        }
        else if (strcmp((kal_char*) tst_inject->string, "stat_fetch") == 0)
        {
            nvram_errno_enum ret;
            nvram_ltable_entry_struct *ldi;
            peer_buff_struct *peer_buf_ptr;
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;
            nvram_read_req_struct *local_data;
            stack_statistics_struct *stat_ptr;
            kal_uint8 i;

            nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_STATISTICS_LID);

            local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
            local_data->access_id = 0;
            local_data->file_idx = (NVRAM_EF_SYS_STATISTICS_LID);
            local_data->para = 1;

            pdu_length = ldi->size;
            peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
            pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);

            /* read statistics information from nvram */
            ret = nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length); /* multi-rec read support */
            /* Send read confirm primitive to nvram itself for catcher display raw data */
            nvram_read_confirm(MOD_NVRAM, ret, local_data, ldi->size, peer_buf_ptr);

            /* Show detail to catcher sys trace window */
            if (ret == NVRAM_IO_ERRNO_OK || ret == NVRAM_IO_ERRNO_INIT)
            {
                stat_ptr = get_ctrl_buffer(ldi->size);

                if (!stat_ptr)
                {
                    nvram_trace(TRACE_FUNC, TEST_RESET_ALLOC_FAIL);
                    return;
                }
                /* stat_ptr = (stack_statistics_struct *)pdu_ptr; */
                kal_mem_cpy(stat_ptr, pdu_ptr, ldi->size);

                nvram_trace(TRACE_FUNC, TEST_SYSINFO_STATUS, stat_ptr->stack_stats_status);
                nvram_trace(TRACE_FUNC, TEST_SYSINFO_MAX_SYSMEM, stat_ptr->max_sys_mem_used);
                nvram_trace(TRACE_FUNC, TEST_SYSINFO_MAX_SYSDBGMEM, stat_ptr->max_sysdebug_mem_used);

                nvram_trace(TRACE_FUNC, TEST_SYSINFO_MAX_TASK_STACK_USED);
                for (i = 0; i < KALTotalTasks; i += 5)
                {
                    kal_trace(TRACE_FUNC, TEST_SYSINFO_DETAIL2,
                        i,
                        ((i > KALTotalTasks ? NULL : task_info_g[i].task_id) == NULL ? "--" : task_info_g[i].task_name_ptr),
                        stat_ptr->max_task_stack_used[i],
                        ((i + 1 > KALTotalTasks ? NULL : task_info_g[i + 1].task_id) == NULL ? "--" : task_info_g[i + 1].task_name_ptr),
                        (i + 1 >= KALTotalTasks) ? 0 : stat_ptr->max_task_stack_used[(i + 1)],
                        ((i + 2 > KALTotalTasks ? NULL : task_info_g[i + 2].task_id) == NULL ? "--" : task_info_g[i + 2].task_name_ptr),
                        (i + 2 >= KALTotalTasks) ? 0 : stat_ptr->max_task_stack_used[(i + 2)],
                        ((i + 3 > KALTotalTasks ? NULL : task_info_g[i + 3].task_id) == NULL ? "--" : task_info_g[i + 3].task_name_ptr),
                        (i + 3 >= KALTotalTasks) ? 0 : stat_ptr->max_task_stack_used[(i + 3)],
                        ((i + 4 > KALTotalTasks ? NULL : task_info_g[i + 4].task_id) == NULL ? "--" : task_info_g[i + 4].task_name_ptr),
                        (i + 4 >= KALTotalTasks) ? 0 : stat_ptr->max_task_stack_used[(i + 4)]);
                    
                }
            #ifdef DEBUG_KAL
                nvram_trace(TRACE_FUNC, TEST_SYSINFO_MAX_HISR_STACK_USED);
                for (i = 0; i < KAL_MAX_NUM_HISRS; i += 5)
                {
                    kal_trace(TRACE_FUNC, TEST_SYSINFO_DETAIL2,
                        i,
                        kal_hisr_ptrs_g[i] == NULL ? "--" : kal_hisr_ptrs_g[i]->hisr_name,
                        stat_ptr->max_hisr_stack_used[i],
                        kal_hisr_ptrs_g[i + 1] == NULL ? "--" : kal_hisr_ptrs_g[i + 1]->hisr_name,
                        (i + 1) >= KAL_MAX_NUM_HISRS ? 0 : stat_ptr->max_hisr_stack_used[(i + 1)],
                        kal_hisr_ptrs_g[i + 2] == NULL ? "--" : kal_hisr_ptrs_g[i + 2]->hisr_name,
                        (i + 2) >= KAL_MAX_NUM_HISRS ? 0 : stat_ptr->max_hisr_stack_used[(i + 2)],
                        kal_hisr_ptrs_g[i + 3] == NULL ? "--" : kal_hisr_ptrs_g[i + 3]->hisr_name,
                        (i + 3) >= KAL_MAX_NUM_HISRS ? 0 : stat_ptr->max_hisr_stack_used[(i + 3)],
                        kal_hisr_ptrs_g[i + 4] == NULL ? "--" : kal_hisr_ptrs_g[i + 4]->hisr_name,
                        (i + 4) >= KAL_MAX_NUM_HISRS ? 0 : stat_ptr->max_hisr_stack_used[(i + 4)]);
                }
            #endif /* DEBUG_KAL */ 

            #ifdef DEBUG_ITC
                nvram_trace(TRACE_FUNC, TEST_SYSINFO_MAX_TASK_EXTQ_ENQED);
                for (i = 0; i < KALTotalTasks; i += 5)
                {
                    kal_trace(TRACE_FUNC, 
                        TEST_SYSINFO_DETAIL2,
                        i,
                        ((i > KALTotalTasks ? NULL : task_info_g[i].task_ext_qid) == NULL ? "--" : task_info_g[i].task_qname_ptr),
                        stat_ptr->max_task_extq_enqued[i],
                        ((i + 1 > KALTotalTasks ? NULL : task_info_g[i + 1].task_ext_qid) == NULL ? "--" : task_info_g[i + 1].task_qname_ptr),
                        (i + 1 >= KALTotalTasks) ? 0 : stat_ptr->max_task_extq_enqued[(i + 1)],
                        ((i + 2 > KALTotalTasks ? NULL : task_info_g[i + 2].task_ext_qid) == NULL ? "--" : task_info_g[i + 2].task_qname_ptr),
                        (i + 2 >= KALTotalTasks) ? 0 : stat_ptr->max_task_extq_enqued[(i + 2)],
                        ((i + 3 > KALTotalTasks ? NULL : task_info_g[i + 3].task_ext_qid) == NULL ? "--" : task_info_g[i + 3].task_qname_ptr),
                        (i + 3 >= KALTotalTasks) ? 0 : stat_ptr->max_task_extq_enqued[(i + 3)],
                        ((i + 4 > KALTotalTasks ? NULL : task_info_g[i + 4].task_ext_qid) == NULL ? "--" : task_info_g[i + 4].task_qname_ptr),
                        (i + 4 >= KALTotalTasks) ? 0 : stat_ptr->max_task_extq_enqued[(i + 4)]);
                }
            #endif /* DEBUG_ITC */ 

            #if (defined(DEBUG_BUF1) || defined(DEBUG_BUF2))
                nvram_trace(TRACE_FUNC, TEST_SYSINFO_CTRLBUFF_ALLOC);
                nvram_trace(TRACE_FUNC, TEST_SYSINFO_CTRLBUFF_LIST);
                
                for (i = 0; i < RPS_CREATED_CTRL_BUFF_POOLS; i += 5)
                {
                    kal_trace(
                        TRACE_FUNC,
                        TEST_SYSINFO_DETAIL1,
                        i,
                        stat_ptr->max_ctrl_buff_num_allocated[i],
                        (i + 1) >= RPS_CREATED_CTRL_BUFF_POOLS ? 0 : stat_ptr->max_ctrl_buff_num_allocated[(i + 1)],
                        (i + 2) >= RPS_CREATED_CTRL_BUFF_POOLS ? 0 : stat_ptr->max_ctrl_buff_num_allocated[(i + 2)],
                        (i + 3) >= RPS_CREATED_CTRL_BUFF_POOLS ? 0 : stat_ptr->max_ctrl_buff_num_allocated[(i + 3)],
                        (i + 4) >= RPS_CREATED_CTRL_BUFF_POOLS ? 0 : stat_ptr->max_ctrl_buff_num_allocated[(i + 4)]);
                }
            #endif /* DEBUG_BUF2 */ 

                free_ctrl_buffer(stat_ptr);

            }
            else
            {
                nvram_trace(TRACE_FUNC, TEST_GET_STAT_FAIL);
            }

        }
        else if (strcmp((kal_char*) tst_inject->string, "reset_all") == 0)
        {
            if (nvram_reset_data_items(NVRAM_RESET_ALL, NVRAM_APP_RESERVED, NULL, 0, 0) != KAL_TRUE)
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_ALL_OK);
            }
            else
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_ALL_FAIL);
            }
        }
        else if (strcmp((kal_char*) tst_inject->string, "reset_certain") == 0)
        {
            nvram_ltable_entry_struct *ldi;

            if (!NVRAM_IS_LID_VALID(tst_inject->index))
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_INVALID_LID);
                return;
            }

            nvram_util_get_data_item(&ldi, tst_inject->index);

            if (nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) != KAL_TRUE)
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_CERTAIN_FAIL);
            }
            else
            {
                nvram_trace(TRACE_FUNC, TEST_RESET_CERTAIN_OK);
            }

        }

        /* Belows are for internal debug testing only. >=) */
        else
        {
            /* Create a exception record manually by issuing a command from Catcher. */
            if (strcmp((kal_char*) tst_inject->string, "ex_create") == 0)
            {
                long *ex_data;

                /* Dynamically allocates buffer, otherwise stack could overflow. */
                ex_data = (long*)get_ctrl_buffer(NVRAM_EF_SYS_EXCEPTION_SIZE);

                kal_mem_set((kal_uint8*) ex_data, 0x5, NVRAM_EF_SYS_EXCEPTION_SIZE);
                nvram_write_exception(NVRAM_EF_SYS_EXCEPTION_SIZE, ex_data);

                free_ctrl_buffer(ex_data);
            }

            /* Update statistics manually by issuing a command from Catcher. */
            else if (strcmp((kal_char*) tst_inject->string, "stat_create") == 0)
            {
                nvram_ltable_entry_struct *ldi;
                stack_statistics_struct *stat_ptr;

                /* Dynamically allocates buffer, otherwise stack could overflow. */
                stat_ptr = (stack_statistics_struct*) get_ctrl_buffer(NVRAM_EF_SYS_STATISTICS_SIZE);
                kal_mem_set((kal_uint8*) stat_ptr, 0, NVRAM_EF_SYS_STATISTICS_SIZE);
                stat_ptr->stack_stats_status = STACK_STATS_UPDATE;

                nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_STATISTICS_LID);

                nvram_write_data_item(ldi, 1, (kal_uint8*) stat_ptr, KAL_FALSE);

                free_ctrl_buffer(stat_ptr);
            }

            /* Test On Demand >>==)) */
            else if (strcmp((kal_char*) tst_inject->string, "nvram_read") == 0)
            {
                nvram_read_req_struct *local_data;

                local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
                local_data->access_id = 0;
                local_data->file_idx = (kal_uint8) tst_inject->index;
                local_data->para = 1;
                nvram_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, local_data, NULL);

            }
            else if (strcmp((kal_char*) tst_inject->string, "sw_lock") == 0)
            {
                nvram_set_lock_req_struct *local_data;

                local_data =
                    (nvram_set_lock_req_struct*) construct_local_para(sizeof(nvram_set_lock_req_struct), TD_CTRL);

                if ((kal_uint8) tst_inject->index == 1)
                {
                    /* Lock */
                    local_data->lock_en = NVRAM_LOCK_ENABLE;
                    nvram_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_SET_LOCK_REQ, local_data, NULL);
                }
                else if ((kal_uint8) tst_inject->index == 0)
                {
                    /* UnLock */
                    local_data->lock_en = NVRAM_LOCK_DISABLE;
                    nvram_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_SET_LOCK_REQ, local_data, NULL);
                }
            }
        #ifdef __NVRAM_UNIT_TEST__
            else if (strcmp((kal_char*) tst_inject->string, "unit_test") == 0)
            {
                nvram_unit_test();
            }
        #endif

        #ifdef __NVRAM_SECURE_DATA_STORAGE__
            /* Error commands */
            else if (strcmp((kal_char*) tst_inject->string, "switch_mode") == 0)
            {
                if (tst_inject->index == 1)
                {
                    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);
                }
                else
                {
                    nvram_access_sds(NVRAM_SDS_ACCESS_RESTORE);
                }
            }
        #endif
            else
            {
                nvram_trace(TRACE_ERROR, ERROR_NVRAM_TST_INVALID_COMM);
            }
        }
    }
    /* State error */
    else
    {
        nvram_trace(TRACE_STATE, STATE_NVRAM_NOT_READY);
    }

}   /* end of nvram_tst_handler */

