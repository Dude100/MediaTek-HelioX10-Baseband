/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_misc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Misc Function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements for KAL
 *************************************************************************/
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
#include "sst_interface.h"
#include "svc_sap.h"
#include "md_sap.h"
#include "ft_msgid.h"
#include "nvram_msgid.h"
#include "sim_public_msgid.h"
/**************************************************************************
 * HAL header
 *************************************************************************/
#include "dcl.h"
/**************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_misc.h"
#include "ft_mem.h"
/**************************************************************************
 * NVRAM header
 *************************************************************************/
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_struct.h"
#include "nvram_interface.h"
#include "nvram_editor_data_item.h"
/* NVRAM private header for data item iterator */
//#include "nvram_util.h" -> "nvram_interface.h"
/**************************************************************************
 * SIM header
 *************************************************************************/
#include "ps2sim_struct.h"
/**************************************************************************
 * Custom header
 *************************************************************************/
#include "meta_customize.h"
kal_uint8  ft_gl_path_check_flag = true;
kal_bool   g_b_ft_nvram_rec = false; // true: get the checksum of the nvram LID, rid
kal_bool   g_b_ft_nvram_proc_locally = false; // true: don't return the CAL integrity data to PC side
int  i4_ft_cur_misc_op = 0;
kal_uint8 *p_ft_misc_buf = NULL;  // a pointer point to : nvram_cal_data_check_struct
kal_bool   b_ft_misc_buf_from_med = true; // true: from MED task, false: from control buffer
#if !defined(NVRAM_NOT_PRESENT)
nvram_cal_data_entry_struct  ft_misc_cal_data_proc_one;
#endif // #if !defined(NVRAM_NOT_PRESENT)
kal_uint16 ft_gl_misc_token = 0;
kal_uint8 ft_gl_sim_cmd_type = 0;  // store sim cmd type

kal_uint8  FT_MISC_SendCnf(FT_MISC_CNF *ft_misc_ret, peer_buff_struct *peer_buff) {

    ilm_struct       ilm_ptr;
    FT_MISC_CNF *ptrMsg;

    FT_ALLOC_MSG(&ilm_ptr, sizeof(FT_MISC_CNF));

    /* if ptrMsg != NULL*/
    ptrMsg = (FT_MISC_CNF *)ilm_ptr.local_para_ptr;

    // assign primitive id
    ptrMsg->header.ft_msg_id = FT_MISC_CMD_CNF_ID;

    // assign return structure
    ptrMsg->type = ft_misc_ret->type;

    // copy the result directly without checking its cmd type
    kal_mem_cpy(&(ptrMsg->result), &(ft_misc_ret->result), sizeof(FT_MISC_CNF_U));

    ptrMsg->status = ft_misc_ret->status;

    // assign peer buffer
    if( NULL != peer_buff ) {
        ilm_ptr.peer_buff_ptr = peer_buff;
    }

    /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
    FT_SEND_MSG_TO_PC_BY_TOKEN(&ilm_ptr, ft_gl_misc_token);
    return 0;
}
#define FT_MISC_MAX_PEER_SIZE       2048
#define FT_MISC_MAX_FRAME_SIZE      FT_MISC_MAX_PEER_SIZE/64*56
#define FT_OTHER_INFO_FLAG 0
#define FT_IMEI_INFO_FLAG  1
#define FT_SML_INFO_FLAG 2
kal_uint8 ft_misc_op_collect_cal_info(FT_MISC_CNF *misc_cnf)
{
    kal_char *pcStrPrefix;
    kal_char *pcStrVerNo;
    kal_uint8  flag;
    peer_buff_struct   *peer_buff_ret = NULL;
    kal_char  *pdu_ptr = NULL;
    kal_uint16  pdu_length = 0;
    kal_uint16  cur_pos = 0;
    nvram_ltable_entry_struct *entry = NULL;
    // find the first enrty when the input pointer is NULL pointer
    nvram_util_next_data_item(&entry);
    do
    {
        if(NVRAM_IO_ERRNO_OK != nvram_check_backup(entry->LID, &pcStrPrefix, &pcStrVerNo))
        {
            continue;
        }
        flag = FT_OTHER_INFO_FLAG;
        if(entry->LID == NVRAM_EF_IMEI_IMEISV_LID)
        {
            flag = FT_IMEI_INFO_FLAG;
        }
        else if(entry->LID==NVRAM_EF_SML_LID)
        {
            flag = FT_SML_INFO_FLAG;
        }
allocate_peer_buf:
        if(NULL == peer_buff_ret)  // allocate peer buffer
        {
            peer_buff_ret=construct_peer_buff(FT_MISC_MAX_FRAME_SIZE, 0, 0, TD_CTRL);
            if(NULL == peer_buff_ret)
            {
                return 1;
            }
            /* Set the pdu_len to 0 to keep track of the current position and updated at each iteration */
            peer_buff_ret->pdu_len = 0 ;
        }
        if( FT_MISC_MAX_FRAME_SIZE < (peer_buff_ret->pdu_len+3+strlen(pcStrPrefix)+strlen(pcStrVerNo)+1) )
        {
            misc_cnf->result.m_u1LastFrame = 0; // set last_frame = 0
            misc_cnf->status = FT_CNF_OK;
            // send confirm
            FT_MISC_SendCnf(misc_cnf, peer_buff_ret);
            // sleep to wait for tst flush out data
            kal_sleep_task(50);
            // allocate peer buffer again
            peer_buff_ret = NULL;
            cur_pos = 0;
            goto allocate_peer_buf;
        }
        pdu_ptr = get_peer_buff_pdu( peer_buff_ret, &pdu_length );
        // copy to peer buffer
        cur_pos = 0;
        // copy lid_value (Assertion check to guarantee that the protocol stays unchange)
        {
            ASSERT(sizeof(kal_uint16) == sizeof(nvram_lid_enum));
            kal_mem_cpy(pdu_ptr+pdu_length, &(entry->LID), sizeof(kal_uint16));
            cur_pos += sizeof(kal_uint16);
        }
        // copy file flag
        {
            kal_mem_cpy(pdu_ptr+pdu_length+cur_pos, &flag, sizeof(kal_uint8));
            cur_pos += sizeof(kal_uint8);
        }
        // copy file prefix (Assertion check to guarantee that the protocol stays unchange)
        {
            ASSERT(strlen(pcStrPrefix) == 4);
            kal_mem_cpy(pdu_ptr+pdu_length+cur_pos, pcStrPrefix, strlen(pcStrPrefix));
            cur_pos +=(strlen(pcStrPrefix));
        }
        // copy lid Ver No (Assertion check to guarantee that the protocol stays unchange)
        {
            ASSERT(strlen(pcStrVerNo) == 3);
            kal_mem_cpy(pdu_ptr+pdu_length+cur_pos, pcStrVerNo, strlen(pcStrVerNo)+1);
            cur_pos += (strlen(pcStrVerNo)+1);
        }
        // update pdu_len
        peer_buff_ret->pdu_len += cur_pos;
    }while(nvram_util_next_data_item(&entry) == KAL_TRUE);
    misc_cnf->result.m_u1LastFrame = 1;
    misc_cnf->status = FT_CNF_OK;
    FT_MISC_SendCnf(misc_cnf, peer_buff_ret);
    return 0;
}
kal_uint8 FT_GetAdcMaxChannel(void)
{
    // HAL modification
    DCL_HANDLE adc_handle;
    ADC_CTRL_GET_MAX_PHYSICAL_CH_T  prGetMaxPhyCh;
    kal_uint8 adc_max_channel;
    adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
    if(DclHADC_Control(adc_handle, ADC_CMD_GET_MAX_PHYSICAL_CH, (DCL_CTRL_DATA_T *)&prGetMaxPhyCh) != STATUS_OK)
    {
        // error handling (prevent from access out-of bound)
        adc_max_channel = 1;
    }
    adc_max_channel = prGetMaxPhyCh.u4Adc_max_ch;
    if(DclSADC_Close(adc_handle) != STATUS_OK)
    {
        // error handling (prevent from access out-of bound)
        adc_max_channel = 1;
    }
    return adc_max_channel;
}

void FT_MISC_Operation(ilm_struct *ptrMsg)
{
    kal_wchar         wpath[128];
    FT_MISC_REQ       *p_req = (FT_MISC_REQ *)ptrMsg->local_para_ptr;
    FT_MISC_CNF       misc_cnf;
    memset(&misc_cnf, 0x0, sizeof(misc_cnf));
    peer_buff_struct  *peer_buff_ret = NULL;  // default value
    kal_char    *pdu_ptr = NULL;
    kal_uint16    pdu_length = 0;
    misc_cnf.type = p_req->type;
    misc_cnf.status = FT_CNF_FAIL;  // default value
    ft_gl_misc_token =  p_req->header.token;

    switch(p_req->type)
    {
        case FT_MISC_OP_GET_IMEI_LOC:
        {
            misc_cnf.result.m_u1IMEILoc = nvram_get_imei_type();
            misc_cnf.status = FT_CNF_OK;
            break;
        }
        case FT_MISC_OP_GET_IMEI_VALUE:
        {
            // check the record index (because tools before 0912 causes assertion)
            kal_uint16 rec_num = nvram_get_imei_record_num();
            if(p_req->cmd.m_u1RecordIndex < 1 || p_req->cmd.m_u1RecordIndex > rec_num)
            {
                // set the record index to 1 (the behavior will be confrom to that of target load before 0909)
                p_req->cmd.m_u1RecordIndex = 1;
            }
            if(KAL_TRUE == nvram_get_imei_value(NVRAM_EF_IMEI_IMEISV_SIZE,
                        misc_cnf.result.m_rIMEIData.buf, p_req->cmd.m_u1RecordIndex))
            {
                misc_cnf.result.m_rIMEIData.buf_len = NVRAM_EF_IMEI_IMEISV_SIZE;
                misc_cnf.status = FT_CNF_OK;
            }
            else
                misc_cnf.status = FT_CNF_FAIL;
            break;

        }
#if defined(__MTK_INTERNAL__)
        case FT_MISC_OP_SET_IMEI_VALUE:
        {
            ilm_struct  ilm_ptr;
            nvram_write_imei_req_struct* ptr_loc_para;
            FT_ALLOC_OTHER_MSG(&ilm_ptr, sizeof(nvram_write_imei_req_struct));
            ptr_loc_para = (nvram_write_imei_req_struct*) (ilm_ptr.local_para_ptr);
            ptr_loc_para->access_id = 0; // access_id (session id)
            ptr_loc_para->record_index = p_req->cmd.m_rIMEIData.record_index;
            memcpy(ptr_loc_para->imei, p_req->cmd.m_rIMEIData.imei, 8);
            ptr_loc_para->svn = p_req->cmd.m_rIMEIData.svn;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_WRITE_IMEI_REQ, &ilm_ptr);
            return;
        }
#endif  //#if defined(__MTK_INTERNAL__)
        case FT_MISC_OP_GET_IMEI_REC_NUM:
        {
            misc_cnf.result.m_u2IMEIRecords = nvram_get_imei_record_num();
            misc_cnf.status = FT_CNF_OK;
            break;
        }
        case FT_MISC_OP_VERIFY_TEMP_SML_FILE:
        {
            //kal_char  *pdu_ptr;
            //kal_uint16    pdu_length;
            kal_wchar *w_filepath;
            // get the file path from peer_buffer
            if(ptrMsg->peer_buff_ptr != NULL)
            {
                pdu_ptr = get_peer_buff_pdu( ptrMsg->peer_buff_ptr, &pdu_length );

                // cast to kal_wchar
                w_filepath = (kal_wchar *)pdu_ptr;

                misc_cnf.status = FT_CNF_OK;

                // ask nvram task to check the SML file
                if(NVRAM_IO_ERRNO_OK == nvram_validate_file(NVRAM_EF_SML_LID, w_filepath))
                    misc_cnf.result.m_u1VerifyResult = FT_SML_VALID;
                else
                    misc_cnf.result.m_u1VerifyResult = FT_SML_INVALID;

            }
            else  // peer buffer is null
            {
                misc_cnf.status = FT_CNF_FAIL;
                misc_cnf.result.m_u1VerifyResult = FT_SML_NO_FILENAME;
            }

            break;
        }
        case FT_MISC_OP_GET_CAL_INFO:
        {
            ft_misc_op_collect_cal_info(&misc_cnf);
            return;
        }
        case FT_MISC_OP_QUERY_NVRAM_FOLDER:
        {
            kal_uint16  length;
            kal_char* buf;
            kal_uint8 folder_total_amount = nvram_get_folder_total_amount();
            kal_int16 total_length = 0;
            kal_int8 i;
            misc_cnf.status = FT_CNF_OK;

            // allocate peer buffer
            if(NULL == peer_buff_ret)
            {//FT_MISC_MAX_FRAME_SIZE
                peer_buff_ret = construct_peer_buff(FT_MISC_MAX_FRAME_SIZE, 0, 0, TD_CTRL);
                if(NULL == peer_buff_ret)  return;

                peer_buff_ret->pdu_len = 0 ;
            }
            pdu_ptr = get_peer_buff_pdu( peer_buff_ret, &pdu_length );
            for(i = 0;i<folder_total_amount;i++)
            {
                buf = nvram_get_work_path(i);
                kal_wsprintf(wpath, "%s", buf);
                if(nvram_check_hidden_file(wpath, true))
                {
                    continue;
                }
                length = (strlen(buf)+1);
                kal_mem_cpy(pdu_ptr+pdu_length+total_length, (buf), length );
                *(pdu_ptr+pdu_length+total_length+length-1) = '?';
                total_length += length;
            }
            // update pdu_len
            peer_buff_ret->pdu_len += (total_length);


            break;
        }
        case FT_MISC_OP_VERIFY_NVRAM_ATTR_SETTING_COMPLETE:
        {
            kal_uint16 stop_index = custom_meta_check_must_backup_lid_array(p_req->cmd.m_bcheckImeiFlag);
            if(stop_index == custom_meta_get_check_lid_num()) // check successfully!
            {
                misc_cnf.status = FT_CNF_OK;
                misc_cnf.result.m_rNvramVerifyResult.m_stop_enum_value = custom_meta_get_enum_by_index(stop_index-1); // pass the imei_enum
                misc_cnf.result.m_rNvramVerifyResult.m_total_lid_num = custom_meta_get_check_lid_num();
                misc_cnf.result.m_rNvramVerifyResult.m_stop_index = stop_index;
            }
            else
            {
                misc_cnf.status = FT_CNF_FAIL;
                misc_cnf.result.m_rNvramVerifyResult.m_stop_enum_value = custom_meta_get_enum_by_index(stop_index);
                misc_cnf.result.m_rNvramVerifyResult.m_total_lid_num = custom_meta_get_check_lid_num();
                misc_cnf.result.m_rNvramVerifyResult.m_stop_index = stop_index;
            }
            break;
        }
        case FT_MISC_OP_ENABLE_PATH_LIMITION:
        case FT_MISC_OP_DISABLE_PATH_LIMITION:
        {
            ft_gl_path_check_flag = (p_req->type == FT_MISC_OP_ENABLE_PATH_LIMITION)?true:false;
            misc_cnf.status = FT_CNF_OK;
            break;
        }
        case FT_MISC_OP_GET_NVRAM_FOLDER_AMOUNT:
        {
            kal_uint8 i;
            misc_cnf.result.m_u1NVRAMFolderAmount = nvram_get_folder_total_amount();
            for(i = 0;i<nvram_get_folder_total_amount();i++)
            {
                kal_wsprintf(wpath, "%s", nvram_get_work_path(i));
                if(nvram_check_hidden_file(wpath, true))
                {
                    misc_cnf.result.m_u1NVRAMFolderAmount--;
                }
            }
            misc_cnf.status = FT_CNF_OK;

        }
        break;
#ifndef SIM_NOT_PRESENT
        case FT_MISC_OP_CHECK_SIM1_INSERTED:
        {
            // Send reset request to MOD_SIM
            ilm_struct  ilm_ptr;
            sim_reset_req_struct* ptr_loc_para;
            FT_ALLOC_OTHER_MSG(&ilm_ptr, sizeof(sim_reset_req_struct));
            ptr_loc_para = (sim_reset_req_struct*) (ilm_ptr.local_para_ptr);
            ptr_loc_para->src_id = 0xff;
            // set sim cmd type to global variable
            ft_gl_sim_cmd_type = FT_MISC_OP_CHECK_SIM1_INSERTED;
            FT_SEND_MSG(MOD_FT, MOD_SIM, PS_SIM_SAP, MSG_ID_SIM_RESET_REQ, &ilm_ptr);
            // wait for SIM task CNF message
            return;
        }
#ifdef __GEMINI__
        case FT_MISC_OP_CHECK_SIM2_INSERTED:
        {
            // Send reset request to MOD_SIM_2
            ilm_struct  ilm_ptr;
            sim_reset_req_struct* ptr_loc_para;
            FT_ALLOC_OTHER_MSG(&ilm_ptr, sizeof(sim_reset_req_struct));
            ptr_loc_para = (sim_reset_req_struct*) (ilm_ptr.local_para_ptr);
            ptr_loc_para->src_id = 0xff;
            // set sim cmd type to global variable
            ft_gl_sim_cmd_type =FT_MISC_OP_CHECK_SIM2_INSERTED;
            FT_SEND_MSG(MOD_FT, MOD_SIM_2, PS_SIM_SAP, MSG_ID_SIM_RESET_REQ, &ilm_ptr);
            // wait for SIM task CNF message
            return;
        }
#endif // __GEMINI__
#ifdef GEMINI_PLUS
        case FT_MISC_OP_CHECK_GEMINI_PLUS_SIM_INSERTED:
        {
            // Send reset request to MOD_SIM_N
            ilm_struct  ilm_ptr;
            sim_reset_req_struct* ptr_loc_para;
            // if index out of range, break and then send error status CNF
            if(p_req->cmd.m_u1SimIndex >= GEMINI_PLUS)
            {
                break;
            }
            FT_ALLOC_OTHER_MSG(&ilm_ptr, sizeof(sim_reset_req_struct));
            ptr_loc_para = (sim_reset_req_struct*) (ilm_ptr.local_para_ptr);
            ptr_loc_para->src_id = 0xff;
            // set sim cmd type to global variable
            ft_gl_sim_cmd_type = FT_MISC_OP_CHECK_GEMINI_PLUS_SIM_INSERTED;
            FT_SEND_MSG(MOD_FT, (module_type)(MOD_SIM + p_req->cmd.m_u1SimIndex), PS_SIM_SAP, MSG_ID_SIM_RESET_REQ, &ilm_ptr);
            // wait for SIM task CNF message
            return;
        }
#endif // GEMINI_PLUS
#endif // SIM_NOT_PRESENT
        case FT_MISC_OP_SET_MUIC_CHARGER_MODE:
        {
#ifdef __DRV_EXT_CHARGER_DETECTION__
            MU_BQ25040_Charger_Mode(p_req->cmd.m_u1ChargerMode);
            misc_cnf.status = FT_CNF_OK;
#else
            misc_cnf.status = FT_CNF_FAIL;

#endif
            break;
        }
#if !defined(NVRAM_NOT_PRESENT)
        case FT_MISC_OP_CALDATA_INTEGRITY_START_REC:
        {
            if(g_b_ft_nvram_rec)
            {
                misc_cnf.status = FT_CNF_FAIL;
                break;
            }


            i4_ft_cur_misc_op =  p_req->type;
            ft_misc_cal_data_read_from_nvram();
            return;
        }
        case FT_MISC_OP_CALDATA_INTEGRITY_STOP_REC:
        {
            if(!g_b_ft_nvram_rec)
            {
                misc_cnf.status = FT_CNF_FAIL;
                break;
            }
            g_b_ft_nvram_rec = false; // stop record
            i4_ft_cur_misc_op =  p_req->type;
            ft_misc_cal_data_write_to_nvram();
            return;
        }
        case FT_MISC_OP_CALDATA_INTEGRITY_ADD_ONE:
        case FT_MISC_OP_CALDATA_INTEGRITY_DEL_ONE:
        case FT_MISC_OP_CALDATA_INTEGRITY_CHECK_ONE:

            ft_misc_cal_data_proc_one.u2LidEnumVal = p_req->cmd.m_rCalDataOne.u2LidEnum;
            ft_misc_cal_data_proc_one.u2LidRec = p_req->cmd.m_rCalDataOne.u2RID;
            ft_misc_cal_data_proc_one.u2CheckVal = 0;
            // note: don't break, keep going
        case FT_MISC_OP_CALDATA_INTEGRITY_DEL_ALL:
        case FT_MISC_OP_CALDATA_INTEGRITY_CHECK_ALL:
        {
            if(g_b_ft_nvram_rec)
            {
                misc_cnf.status = FT_CNF_FAIL;
                break;
            }
            i4_ft_cur_misc_op =  p_req->type;

            ft_misc_cal_data_read_from_nvram();
            return;
        }
#endif // #if !defined(NVRAM_NOT_PRESENT)
        case FT_MISC_OP_GET_ADC_FROM_EFUSE:
        {
            kal_bool b_ret_code;
            kal_uint8 i;
            kal_uint8 adc_max_channel;
            DCL_HANDLE adc_handle;
            ADC_CTRL_READ_CALIBRATION_DATA_T prReadCalibrationData;
            adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
            adc_max_channel = FT_GetAdcMaxChannel();
            b_ret_code = (STATUS_OK == DclSADC_Control(adc_handle, ADC_CMD_READ_CALIBRATION_DATA, (DCL_CTRL_DATA_T*)&prReadCalibrationData)) ?
                KAL_TRUE : KAL_FALSE;
            misc_cnf.status = FT_CNF_OK;
            misc_cnf.result.m_rGetAdcFromEfuse.bADCStoredInEfuse = b_ret_code;
            misc_cnf.result.m_rGetAdcFromEfuse.u2ADCChnNum = b_ret_code ? adc_max_channel : 0;

            // if channel number > 0, construct peer buffer
            if(misc_cnf.result.m_rGetAdcFromEfuse.u2ADCChnNum > 0) // i.e. FT_GetAdcMaxChannel()
            {
                if( NULL != (peer_buff_ret=construct_peer_buff(adc_max_channel*8, 0, 0, TD_CTRL)) )
                {
                    pdu_ptr = get_peer_buff_pdu( peer_buff_ret, &pdu_length );
                    peer_buff_ret->pdu_len = adc_max_channel *8;

                    for(i =0; i< adc_max_channel; i++) // append slope first
                    {
                        kal_mem_cpy(pdu_ptr+(i*4), &(prReadCalibrationData.i4ADCSlope[i]), sizeof(kal_int32));
                    }
                    for(i =0; i<adc_max_channel; i++) // append offset second
                    {
                        kal_mem_cpy(pdu_ptr+((adc_max_channel+i)*4), &(prReadCalibrationData.i4ADCOffset[i]), sizeof(kal_int32));
                    }
                }
            }
            break;
        }
        case FT_MISC_OP_GET_CALFLAG_ENUM:
        {
                 misc_cnf.result.m_u2CalFlagEnum = custom_ft_get_calflag_enum();
                 misc_cnf.status = FT_CNF_OK;
        }
        break;
        case FT_MISC_OP_GET_ADC_MAX_CHANNEL:
        {
            // HAL modification
            misc_cnf.status = FT_CNF_OK;
            misc_cnf.result.m_u1ADCMaxChannel = FT_GetAdcMaxChannel();
            break;
        }
        case FT_MISC_OP_GET_TADC_INDEX:
        {
            // HAL modification
            //misc_cnf.result.m_u1TADCChannelIndex = custom_adc_get_channel(rftmp_adc_channel);
            DCL_HANDLE adc_handle;
            ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
            misc_cnf.status = FT_CNF_OK;
            adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
            adc_ch.u2AdcName = DCL_RFTMP_ADC_CHANNEL;
            if(DclSADC_Control( adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)& adc_ch) != STATUS_OK)
            {
                misc_cnf.status = FT_CNF_FAIL;
            }
            misc_cnf.result.m_u1TADCChannelIndex = adc_ch.u1AdcPhyCh;
            if(DclSADC_Close(adc_handle) != STATUS_OK)
            {
                misc_cnf.status = FT_CNF_FAIL;
            }
            break;
        }       
        case FT_MISC_OP_GET_RF_CAL_ENV_ENUM:
            misc_cnf.result.m_u2Enum = custom_ft_get_rf_cal_env_enum();
            misc_cnf.status = FT_CNF_OK;
        break;
        case FT_MISC_OP_GET_RF_CAL_LOSS_SETTING_ENUM:
            misc_cnf.result.m_u2Enum = custom_ft_get_rf_loss_setting_enum();
            misc_cnf.status = FT_CNF_OK;
        break;
        case FT_MISC_OP_GET_RF_TEST_POWER_RESULT_ENUM:
            misc_cnf.result.m_u2Enum = custom_ft_get_rf_test_power_result_enum();
            misc_cnf.status = FT_CNF_OK;
        break;
        case FT_MISC_OP_GET_RID:
        {
            if(KAL_TRUE == SST_Get_ChipRID((kal_char*)misc_cnf.result.m_rRIDData.buf, (p_req->cmd.m_RIDLength*8)))
            {
                misc_cnf.result.m_rRIDData.buf_len = p_req->cmd.m_RIDLength; // return RID length in bytes
            }
            else
            {
                misc_cnf.result.m_rRIDData.buf_len = 0; // return length = 0 for error check
            }
            misc_cnf.status = FT_CNF_OK;
            break;
        }
        case FT_MISC_OP_GET_BARCODE_VALUE:
        {
            if(p_req->cmd.m_u1RecordIndex < 1 || p_req->cmd.m_u1RecordIndex > NVRAM_EF_BARCODE_NUM_TOTAL)
            {
                p_req->cmd.m_u1RecordIndex = 1;
            }
            if( NULL != (peer_buff_ret=construct_peer_buff(NVRAM_EF_BARCODE_NUM_SIZE, 0, 0, TD_CTRL)))
            {
                peer_buff_ret->pdu_len = NVRAM_EF_BARCODE_NUM_SIZE;
                pdu_ptr = get_peer_buff_pdu( peer_buff_ret, &pdu_length );    	                           
                if(KAL_TRUE == nvram_external_read_data(NVRAM_EF_BARCODE_NUM_LID, p_req->cmd.m_u1RecordIndex, (kal_uint8*)pdu_ptr, NVRAM_EF_BARCODE_NUM_SIZE))
                {
                    misc_cnf.status = FT_CNF_OK;
                }
            }
            break;
        }        
        case FT_MISC_OP_CHECK_SIM_HW_TEST:
        {
#if !defined(SIM_NOT_PRESENT)
            extern int usim_iftest_for_smt(kal_uint32 SIM_index);
            kal_int32 status;
            tst_sys_trace("calling usim_iftest_for_smt");
            status = usim_iftest_for_smt(p_req->cmd.m_u1SimIndex);
            tst_sys_trace("exit usim_iftest_for_smt");
            kal_mem_cpy(&(misc_cnf.result.m_i4SimHwStatus), &status, sizeof(kal_int32));
            misc_cnf.status = FT_CNF_OK;
#else // #if !defined(SIM_NOT_PRESENT)
            kal_int32* pStatus = (kal_uint32*) &(misc_cnf.result.m_i4SimHwStatus);
            *pStatus = 0;
            misc_cnf.status = FT_CNF_FAIL;
#endif // #if defined(SIM_NOT_PRESENT)
            break;
        }
        default:
            return;
    }
    // send confirm to PC side
    FT_MISC_SendCnf(&misc_cnf, peer_buff_ret);
}

bool ft_misc_cal_data_allocate_buf(void)
{
#if !defined(NVRAM_NOT_PRESENT)
    // allocate the buffer
    if(p_ft_misc_buf == NULL) // allocate the buffer to store PCM data from PC-side
    {
        p_ft_misc_buf = (kal_uint8*)FtAllocExtMemory(NVRAM_EF_CAL_DATA_CHECK_SIZE);
        if(p_ft_misc_buf == NULL)
        {
            return false;
        }
        b_ft_misc_buf_from_med = true;
    }
    // check if the buffer pointer not NULL
    if(p_ft_misc_buf == NULL)
    {
        return false;
    }
#endif // #if !defined(NVRAM_NOT_PRESENT)
    return true;
}

bool ft_misc_cal_data_read_from_nvram(void)
{
    ft_nvram_read_req_struct_T req;
    req.file_idx = NVRAM_EF_CAL_DATA_CHECK_LID;
    req.para = NVRAM_EF_CAL_DATA_CHECK_TOTAL; // 1
#ifdef __NVRAM_SECRET_DATA__
         req.ciphered_data_valid = false;
#endif // #ifdef __NVRAM_SECRET_DATA__

    // send message to nvram
    g_b_ft_nvram_proc_locally = true; // true: don't return the CAL integrity data to PC side

    FT_ReadFrom_NVRAM(&req);
    return true;
}

bool ft_misc_cal_data_read_from_nvram_cnf(nvram_read_cnf_struct*  cnf_result,
        peer_buff_struct*       peer_buff )
{
#if !defined(NVRAM_NOT_PRESENT)
    FT_MISC_CNF             misc_cnf;
    //peer_buff_struct     *peer_buff_ret = NULL;  // default value
    kal_char    *pdu_ptr = NULL;
    kal_uint16    pdu_length = 0;
    kal_bool b_ret_cnf_to_pc = KAL_FALSE;

    misc_cnf.type = (FT_MISC_CMD_TYPE)i4_ft_cur_misc_op;
    misc_cnf.status = FT_CNF_FAIL;  // default value

    g_b_ft_nvram_proc_locally = false;

    if(!ft_misc_cal_data_allocate_buf())
        return false;
    pdu_ptr = get_peer_buff_pdu( peer_buff, &pdu_length );

    // copy the content from nvram to local buffer
    kal_mem_cpy(p_ft_misc_buf, pdu_ptr, NVRAM_EF_CAL_DATA_CHECK_SIZE);

    switch(i4_ft_cur_misc_op)
    {
        case FT_MISC_OP_CALDATA_INTEGRITY_START_REC:
        {
            nvram_cal_data_check_struct *cal_data = (nvram_cal_data_check_struct*) p_ft_misc_buf;
            g_b_ft_nvram_rec = true; // true: get the checksum of the nvram LID, rid
            misc_cnf.result.m_u1CurRecNum = cal_data->u1ValidNum;
            misc_cnf.status = FT_CNF_OK;
            b_ret_cnf_to_pc = true;
            break;
        }

        case FT_MISC_OP_CALDATA_INTEGRITY_ADD_ONE:
        {
            bool ret;

            ret = ft_misc_cal_data_get_checksum(
                    ft_misc_cal_data_proc_one.u2LidEnumVal,
                    ft_misc_cal_data_proc_one.u2LidRec,
                    &ft_misc_cal_data_proc_one.u2CheckVal);
            if(ret)
            {
                // update the misc_buffer
                ft_misc_cal_data_update_local_buf(ft_misc_cal_data_proc_one.u2LidEnumVal,
                        ft_misc_cal_data_proc_one.u2LidRec, ft_misc_cal_data_proc_one.u2CheckVal);
                // write to nvram
                ft_misc_cal_data_write_to_nvram();
            }
            else
            {
                misc_cnf.status = FT_CNF_FAIL;
                b_ret_cnf_to_pc = true;
            }

        }
        break;
        case FT_MISC_OP_CALDATA_INTEGRITY_DEL_ONE:
        case FT_MISC_OP_CALDATA_INTEGRITY_DEL_ALL:
        {
            bool bOne = i4_ft_cur_misc_op == FT_MISC_OP_CALDATA_INTEGRITY_DEL_ONE? true: false;
            if(!ft_misc_cal_data_del_from_local_buf(bOne))
            {
                misc_cnf.status = FT_CNF_FAIL;
                b_ret_cnf_to_pc = true;
            }
            else // delete success;
            {
                // write to nvram
                ft_misc_cal_data_write_to_nvram();
            }
            break;
        }
        case FT_MISC_OP_CALDATA_INTEGRITY_CHECK_ONE:
        case FT_MISC_OP_CALDATA_INTEGRITY_CHECK_ALL:
        {
            bool bret;
            bool bOne = i4_ft_cur_misc_op == FT_MISC_OP_CALDATA_INTEGRITY_CHECK_ONE? true: false;
            bret = ft_misc_cal_data_check(bOne);
            if(bOne)
            {
                if(!bret)
                    misc_cnf.status = FT_CNF_FAIL;
                else
                {
                    misc_cnf.status = FT_CNF_OK;
                }
            }
            else// if(!bOne)
            {

                misc_cnf.result.m_rCalCheckAll.bAllPass = bret;
                misc_cnf.result.m_rCalCheckAll.u2LastLID = ft_misc_cal_data_proc_one.u2LidEnumVal ;
                misc_cnf.result.m_rCalCheckAll.u2LastRID = ft_misc_cal_data_proc_one.u2LidRec;
                misc_cnf.status = FT_CNF_OK;
            }
            b_ret_cnf_to_pc = true;
            // release allocate buffer
            ft_misc_cal_data_free_alloc_buf();
            break;
        }
        default: // exFT_MISC_OP_CALDATA_INTEGRITY_STOP_REC:
            return true; // do nothing
    }
    if(b_ret_cnf_to_pc)
        FT_MISC_SendCnf(&misc_cnf, NULL); // send confirm to PC side
#endif // #if !defined(NVRAM_NOT_PRESENT)
    return true;
}

bool ft_misc_cal_data_write_to_nvram(void)
{
#if !defined(NVRAM_NOT_PRESENT)
    ft_nvram_write_req_struct_T req;
    peer_buff_struct *peer_buff = NULL;
    kal_char  *pdu_ptr = NULL;
    kal_uint16    pdu_length = 0;

    req.file_idx = NVRAM_EF_CAL_DATA_CHECK_LID;
    req.para = NVRAM_EF_CAL_DATA_CHECK_TOTAL; // 1
#ifdef __NVRAM_SECRET_DATA__
    req.msg_num = 1;
    req.msg_idx = 0;
#endif // #ifdef __NVRAM_SECRET_DATA__

    // allocate a peer buffer
    if( NULL != (peer_buff=construct_peer_buff(NVRAM_EF_CAL_DATA_CHECK_SIZE,
                    0, 0, TD_CTRL)) )
    {
        pdu_ptr = get_peer_buff_pdu( peer_buff, &pdu_length );
        kal_mem_cpy(pdu_ptr,p_ft_misc_buf , NVRAM_EF_CAL_DATA_CHECK_SIZE);
        peer_buff->pdu_len = NVRAM_EF_CAL_DATA_CHECK_SIZE;
        g_b_ft_nvram_proc_locally = true;
        // send message to NVRAM
        FT_WriteTo_NVRAM(&req, peer_buff, NULL);
        peer_buff = NULL;/* the NVRAM will release the mem*/
        return true;
    }
    else
    {
        return false;
    }
#else // #if !defined(NVRAM_NOT_PRESENT)
    return true;
#endif // #if defined(NVRAM_NOT_PRESENT)
}

bool ft_misc_cal_data_write_to_nvram_cnf(nvram_write_cnf_struct*  cnf_result )
{
#if !defined(NVRAM_NOT_PRESENT)
    FT_MISC_CNF              misc_cnf;
    misc_cnf.status = cnf_result->result;
    misc_cnf.type = (FT_MISC_CMD_TYPE)i4_ft_cur_misc_op;
    g_b_ft_nvram_proc_locally = false;
    switch(i4_ft_cur_misc_op)
    {
        case FT_MISC_OP_CALDATA_INTEGRITY_STOP_REC:
        case FT_MISC_OP_CALDATA_INTEGRITY_ADD_ONE:
        case FT_MISC_OP_CALDATA_INTEGRITY_DEL_ONE:
        case FT_MISC_OP_CALDATA_INTEGRITY_DEL_ALL:
        {
            if(p_ft_misc_buf)
            {
                nvram_cal_data_check_struct *cal_data = (nvram_cal_data_check_struct*) p_ft_misc_buf;
                misc_cnf.result.m_u1CurRecNum = cal_data->u1ValidNum;
            }
            break;
        }

        default:
            return false;
    }

    FT_MISC_SendCnf(&misc_cnf, NULL); // send confirm to PC side
    ft_misc_cal_data_free_alloc_buf();
#endif // #if !defined(NVRAM_NOT_PRESENT)
    return true;
}
bool ft_misc_cal_data_get_checksum(kal_uint16 file_idx,
        kal_uint16 rec_idx,
        kal_uint16 *pu2_checksum)
{
    bool bValid = nvram_external_read_chksum(file_idx,
            rec_idx, 1, (kal_uint8*)pu2_checksum, sizeof(kal_uint16));
    return bValid;
}
//=============== local buffer process =========================
void ft_misc_cal_data_free_alloc_buf(void)
{
    if(p_ft_misc_buf) // free the buffer
    {
        if(b_ft_misc_buf_from_med) // free the buffer we borrow from MED task
        {
            FtFreeExtMemory(p_ft_misc_buf);
        }
        else // free the control buffer
        {
            free_ctrl_buffer(p_ft_misc_buf);
        }
        p_ft_misc_buf = NULL;
    }
}

bool  ft_misc_cal_data_update_local_buf( kal_uint16 file_idx,
        kal_uint16 rec_idx,
        kal_uint16 u2_checksum)

{
#if !defined(NVRAM_NOT_PRESENT)
    kal_uint8 i=0;
    kal_uint8 insert_idx = nvram_cal_data_entry_num;

    nvram_cal_data_check_struct *cal_data = (nvram_cal_data_check_struct*) p_ft_misc_buf;
    if( cal_data->u1ValidNum == 0)
    {
        cal_data->CalDataCheck[0].u2LidEnumVal = file_idx;
        cal_data->CalDataCheck[0].u2LidRec = rec_idx;
        cal_data->CalDataCheck[0].u2CheckVal = u2_checksum;
        cal_data->u1ValidNum++;
        return true;
    }
    else if(cal_data->CalDataCheck[cal_data->u1ValidNum-1].u2LidEnumVal < file_idx ||
            (cal_data->CalDataCheck[cal_data->u1ValidNum-1].u2LidEnumVal == file_idx &&
             cal_data->CalDataCheck[cal_data->u1ValidNum-1].u2LidRec < rec_idx )
           )
    {
        if(cal_data->u1ValidNum < nvram_cal_data_entry_num-1)
        {
            // append at the end
            cal_data->CalDataCheck[cal_data->u1ValidNum].u2LidEnumVal = file_idx;
            cal_data->CalDataCheck[cal_data->u1ValidNum].u2LidRec = rec_idx;
            cal_data->CalDataCheck[cal_data->u1ValidNum].u2CheckVal = u2_checksum;
            cal_data->u1ValidNum++;
            return true;
        }
        else // exceed the allowed number in NVRAM
            return false;
    }
    // find the same one
    for(i=0; i< cal_data->u1ValidNum && i<nvram_cal_data_entry_num;i++)
    {
        if(cal_data->CalDataCheck[i].u2LidEnumVal == file_idx &&
                cal_data->CalDataCheck[i].u2LidRec == rec_idx)
        {
            cal_data->CalDataCheck[i].u2CheckVal = u2_checksum;
            return true;
        }
    }
    // find right position, and update the remaining buffer, and insert it!
    for(i = 0;
            i<cal_data->u1ValidNum&& i<nvram_cal_data_entry_num-1;
            i++)
    {

        if(cal_data->CalDataCheck[i].u2LidEnumVal < file_idx &&
                cal_data->CalDataCheck[i+1].u2LidEnumVal > file_idx)
        {
            // find one;
            insert_idx = i+1;
            break;
        }
        else if(cal_data->CalDataCheck[i].u2LidEnumVal == file_idx)
        {

            if(cal_data->CalDataCheck[i].u2LidRec > rec_idx)
            {
                insert_idx = i;
                break;
            }
            else // smaller record
            {
                // check if next one
                if(cal_data->CalDataCheck[i+1].u2LidEnumVal > file_idx)
                {
                    insert_idx = i+1;
                    break;
                }
                else if(cal_data->CalDataCheck[i+1].u2LidEnumVal == file_idx)
                {
                    if(cal_data->CalDataCheck[i+1].u2LidRec > rec_idx)
                    {
                        insert_idx = i+1;
                        break;
                    }
                }
            }
        }
        else if(cal_data->CalDataCheck[i].u2LidEnumVal > file_idx)
        {
            insert_idx = i;
            break;
        }
    }
    if(insert_idx < nvram_cal_data_entry_num &&
            cal_data->u1ValidNum < nvram_cal_data_entry_num-1)
    {
        for( i = cal_data->u1ValidNum; i>insert_idx; i--)
        {
            cal_data->CalDataCheck[i].u2LidEnumVal = cal_data->CalDataCheck[i-1].u2LidEnumVal;
            cal_data->CalDataCheck[i].u2LidRec = cal_data->CalDataCheck[i-1].u2LidRec;
            cal_data->CalDataCheck[i].u2CheckVal = cal_data->CalDataCheck[i-1].u2CheckVal;
        }
        cal_data->CalDataCheck[insert_idx].u2LidEnumVal = file_idx;
        cal_data->CalDataCheck[insert_idx].u2LidRec = rec_idx;
        cal_data->CalDataCheck[insert_idx].u2CheckVal = u2_checksum;
        cal_data->u1ValidNum++;
    }
    else
        return false;
#endif // #if !defined(NVRAM_NOT_PRESENT)
    return true;
}

bool ft_misc_cal_data_del_from_local_buf(bool bOne)
{
#if !defined(NVRAM_NOT_PRESENT)
    if(!p_ft_misc_buf)
        return false;
    else
    {
        kal_uint8 i;

        nvram_cal_data_check_struct *cal_data = (nvram_cal_data_check_struct*) p_ft_misc_buf;

        if(bOne)
        {
            kal_uint8 remove_idx = 0;
            // locate the index;
            for(i =0; i< cal_data->u1ValidNum; i++)
            {
                if(cal_data->CalDataCheck[i].u2LidEnumVal == ft_misc_cal_data_proc_one.u2LidEnumVal &&
                        cal_data->CalDataCheck[i].u2LidRec ==ft_misc_cal_data_proc_one.u2LidRec )
                {
                    remove_idx = i;
                    break;
                }
            }

            if(i != cal_data->u1ValidNum) // find one
            {
                        for(i = remove_idx; i< cal_data->u1ValidNum && i<nvram_cal_data_entry_num-1; i++) // the last one will be 0
                {
                    cal_data->CalDataCheck[i].u2LidEnumVal = cal_data->CalDataCheck[i+1].u2LidEnumVal;
                    cal_data->CalDataCheck[i].u2LidRec = cal_data->CalDataCheck[i+1].u2LidRec;
                    cal_data->CalDataCheck[i].u2CheckVal = cal_data->CalDataCheck[i+1].u2CheckVal;
                }
                cal_data->u1ValidNum--;
            }
        }
        else // delete all
        {
            for(i = 0; i< cal_data->u1ValidNum; i++)
            {
                cal_data->CalDataCheck[i].u2LidEnumVal = 0;
                cal_data->CalDataCheck[i].u2LidRec = 0;
                cal_data->CalDataCheck[i].u2CheckVal = 0;
            }
            cal_data->u1ValidNum = 0;
        }
    }
#endif // #if !defined(NVRAM_NOT_PRESENT)
    return true;
}

bool ft_misc_cal_data_check(bool bOne)
{
#if !defined(NVRAM_NOT_PRESENT)
    if(!p_ft_misc_buf)
        return false;
    else
    {
        kal_uint8 i;

        nvram_cal_data_check_struct *cal_data = (nvram_cal_data_check_struct*) p_ft_misc_buf;

        if(bOne)
        {
            // locate the index;
            for(i =0; i< cal_data->u1ValidNum; i++)
            {
                if(cal_data->CalDataCheck[i].u2LidEnumVal == ft_misc_cal_data_proc_one.u2LidEnumVal &&
                        cal_data->CalDataCheck[i].u2LidRec ==ft_misc_cal_data_proc_one.u2LidRec )
                {

                    break;
                }
            }
            if(i != cal_data->u1ValidNum) // find one
            {
                // get checksum from nvram
                kal_uint16 u2CheckSum;
                if(!ft_misc_cal_data_get_checksum(ft_misc_cal_data_proc_one.u2LidEnumVal,
                            ft_misc_cal_data_proc_one.u2LidRec, &u2CheckSum))
                    return false;
                else
                {
                    if(u2CheckSum != cal_data->CalDataCheck[i].u2CheckVal)
                        return false;

                }

            }
            else
                return false; // can not find one to check!

        }
        else // check all
        {
            kal_uint16 u2CheckSum;
            if(cal_data->u1ValidNum == 0) // at least one item to check
                return false;
            for(i =0; i< cal_data->u1ValidNum; i++)
            {
                ft_misc_cal_data_proc_one.u2LidEnumVal = cal_data->CalDataCheck[i].u2LidEnumVal;
                ft_misc_cal_data_proc_one.u2LidRec = cal_data->CalDataCheck[i].u2LidRec;

                if(!ft_misc_cal_data_get_checksum(cal_data->CalDataCheck[i].u2LidEnumVal,
                            cal_data->CalDataCheck[i].u2LidRec, &u2CheckSum))
                    return false;
                else
                {
                    if(u2CheckSum != cal_data->CalDataCheck[i].u2CheckVal)
                    {
                        return false;
                    }
                }

            }

        }
    }
#endif // #if !defined(NVRAM_NOT_PRESENT) 
    return true;
}
kal_uint32 FT_MiscCheckFunctionSupported(kal_uint32 query_op_code)
{
    kal_uint32 cnf_code;
    if(FT_MISC_OP_END> query_op_code)
    {
        if(FT_MISC_OP_SET_IMEI_VALUE == query_op_code)
        {
            cnf_code = FT_CNF_FAIL;
#if defined(__MTK_INTERNAL__)
            cnf_code = FT_CNF_OK;
#endif  //#if defined(__MTK_INTERNAL__)
        }
        else if(FT_MISC_OP_SET_WIFI_MAC_ADDR == query_op_code)
        {
            cnf_code = FT_CNF_FAIL;
        }
        else if(FT_MISC_OP_SET_MUIC_CHARGER_MODE == query_op_code)
        {
#ifdef __DRV_EXT_CHARGER_DETECTION__
            cnf_code = FT_CNF_OK;
#else
            cnf_code = FT_CNF_FAIL;

#endif
        }
        else if(
                (FT_MISC_OP_GET_RF_CAL_ENV_ENUM == query_op_code) ||
                (FT_MISC_OP_GET_RF_CAL_LOSS_SETTING_ENUM == query_op_code) ||
                (FT_MISC_OP_GET_RF_TEST_POWER_RESULT_ENUM == query_op_code)
               )
        {
#ifdef __TC01__
            cnf_code = FT_CNF_OK;
#else
            cnf_code = FT_CNF_FAIL;
#endif
        }
        else if(FT_MISC_OP_GET_MMI_CACHE_ENUM_INDEX == query_op_code)
        {
            cnf_code = FT_CNF_FAIL;
        }
        else if(FT_MISC_OP_CHECK_SIM_HW_TEST == query_op_code)
        {
#if !defined(SIM_NOT_PRESENT)
            cnf_code = FT_CNF_OK;
#else // #if !defined(SIM_NOT_PRESENT)
            cnf_code = FT_CNF_FAIL;
#endif // #if defined(SIM_NOT_PRESENT)
        }
        else
        {
            cnf_code = FT_CNF_OK;
        }
    }
    else
    {
        cnf_code = FT_CNF_FAIL;
    }
    return cnf_code;
}
