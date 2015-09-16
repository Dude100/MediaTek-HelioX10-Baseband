/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_misc_ex.c
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
#include "svc_sap.h"
#include "ft_msgid.h"
#include "nvram_msgid.h"
/**************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_misc_ex.h"
/**************************************************************************
 * Custom header
 *************************************************************************/
#include "meta_customize.h"
#if defined(__TC01_ERS_SUPPORT__)
// FIXME: remove the compile option wrapping after GOLF QM
#include "ers_type.h"
#include "ers_api.h"
#endif // #if defined(__TC01_ERS_SUPPORT__)

#if defined(__FS_RAMDISK__)
// added for ram disk dump
#include "ramdisk_gprot.h"
#endif //#if defined(__FS_RAMDISK__) 

// INT_SetCmdToSys
#include "init.h"

kal_uint16 ft_gl_misc_ex_token = 0;
kal_uint8  *ft_gl_misc_ex_buf = NULL;
kal_uint8  FT_MISC_EX_SendCnf(FT_MISC_EX_CNF *ft_misc_ret, peer_buff_struct *peer_buff)
{

    ilm_struct           ilm_ptr;
    FT_MISC_EX_CNF  *ptrMsg;

    FT_ALLOC_MSG(&ilm_ptr, sizeof(FT_MISC_EX_CNF));

    /* if ptrMsg != NULL*/
    ptrMsg = (FT_MISC_EX_CNF *)ilm_ptr.local_para_ptr;

    // assign primitive id
    ptrMsg->header.ft_msg_id = FT_MISC_EX_CMD_CNF_ID;

    // assign return structure
    ptrMsg->type = ft_misc_ret->type;

    // copy the result directly without checking its cmd type
    kal_mem_cpy(&(ptrMsg->result), &(ft_misc_ret->result), sizeof(FT_MISC_EX_CNF_U));

    ptrMsg->status = ft_misc_ret->status;

    // assign peer buffer
    if( NULL != peer_buff )
    {
        ilm_ptr.peer_buff_ptr = peer_buff;
    }

    FT_SEND_MSG_TO_PC_BY_TOKEN(&ilm_ptr, ft_gl_misc_ex_token);    
    return 0;
}

#if defined(__TC01_ERS_SUPPORT__)
void FT_ReadERS_Data(ilm_struct *ptrMsg)
{
    kal_uint16        pdu_length_in;
    kal_char          *pdu_ptr_in;
    FT_MISC_EX_CNF      misc_ex_cnf;
    kal_int32         ers_data_size;
    kal_uint8         *p_ers_data ;
    kal_int32         ers_data_idx;
    kal_uint32        u4CurOffset = 0;




    misc_ex_cnf.type = FT_MISC_EX_OP_GET_ERS_DATA;
    misc_ex_cnf.status = FT_CNF_FAIL;  // default value
    ers_data_size = ERS_query_size(); //wise_query_ERS_size();

    if( NULL != ptrMsg->peer_buff_ptr )
    {
        pdu_ptr_in = get_peer_buff_pdu( ptrMsg->peer_buff_ptr, &pdu_length_in );
    }
    kal_mem_cpy(&ers_data_idx, pdu_ptr_in, 4);
    p_ers_data = (kal_uint8*)ERS_query_content_by_idx(ers_data_idx);//wise_query_ERS_content((WCHAR *)pdu_ptr_in);

    // organize the buffer, and send it sequentially to PC side
    if(p_ers_data != NULL)
    {
        // allocate the peer buffer to send to PC-side
        while(u4CurOffset < ers_data_size)
        {

            peer_buff_struct *peer_buff = NULL;
            kal_char *pdu_ptr = NULL;
            kal_uint16   pdu_length = 0;
            kal_uint16  u2_cur_len = FT_MISC_EX_DATA_FRAME_SIZE; // default: 1800 bytes to send

            misc_ex_cnf.result.m_rErsDataFrm.m_u4TotalSize = ers_data_size;
            misc_ex_cnf.result.m_rErsDataFrm.m_u4CurOffset = u4CurOffset;
            if(u4CurOffset+FT_MISC_EX_DATA_FRAME_SIZE >= ers_data_size)
            {
                misc_ex_cnf.result.m_rErsDataFrm.m_bLastFrm = true;
                u2_cur_len =  ers_data_size - u4CurOffset;
            }
            else
                misc_ex_cnf.result.m_rErsDataFrm.m_bLastFrm = false;

            // allocate a peer buffer
            if( NULL != (peer_buff=construct_peer_buff(u2_cur_len,  0, 0, TD_CTRL)) )
            {
                pdu_ptr = get_peer_buff_pdu( peer_buff, &pdu_length );
                kal_mem_cpy(pdu_ptr, p_ers_data+u4CurOffset , u2_cur_len);
                peer_buff->pdu_len = u2_cur_len;
            }
            misc_ex_cnf.status = FT_CNF_OK;
            FT_MISC_EX_SendCnf(&misc_ex_cnf, peer_buff);
            kal_sleep_task(50);

            peer_buff = NULL;// the mem will be released by FT task when copy to TST buffer
            u4CurOffset += u2_cur_len;


        }

    }
    else
    {
        misc_ex_cnf.status = 0xFF;
        FT_MISC_EX_SendCnf(&misc_ex_cnf, NULL);
    }

}
#endif // #if defined(__TC01_ERS_SUPPORT__)

void FT_Handle_CNF_From_NVRAM(ilm_struct* ptrMsgCnf)
{
    FT_MISC_EX_CNF misc_ex_cnf;
    memset(&misc_ex_cnf,0x0,sizeof(misc_ex_cnf));
    peer_buff_struct *peer_buff_ret = NULL;  // default value
    misc_ex_cnf.status = FT_CNF_FAIL;  // default value
    switch (ptrMsgCnf->msg_id)
    {
#if defined(__MOD_NVRAM__)&& defined(__SYSDRV_BACKUP_DISK_RAW__)
        case  MSG_ID_NVRAM_CREATE_IMAGE_CNF:
        {
            nvram_create_image_cnf_struct *cnf = (nvram_create_image_cnf_struct*)ptrMsgCnf->local_para_ptr;
            misc_ex_cnf.type = (FT_MISC_EX_CMD_TYPE)cnf->access_id;//FT_MISC_EX_OP_COPY_NVRAM_TO_BP_AREA;
            misc_ex_cnf.status = cnf->result;
            break;
        }
        case MSG_ID_NVRAM_VERIFY_IMAGE_CNF:
        {
            nvram_verify_image_cnf_struct *cnf = (nvram_verify_image_cnf_struct*)ptrMsgCnf->local_para_ptr;
            misc_ex_cnf.type = (FT_MISC_EX_CMD_TYPE)cnf-> access_id; //FT_MISC_EX_OP_VERIFY_BP_AREA;
            misc_ex_cnf.status = FT_CNF_OK;
            if(cnf->result == NVRAM_ERRNO_SUCCESS)
                misc_ex_cnf.result.m_u4BPStatus = META_BP_AREA_STATUS_OK;
            else if(cnf->result == NVRAM_ERRNO_IMAGE_EMPTY)
                misc_ex_cnf.result.m_u4BPStatus = META_BP_AREA_STATUS_EMPTY;
            else if(cnf->result == NVRAM_ERRNO_IMAGE_BROKEN)
                misc_ex_cnf.result.m_u4BPStatus = META_BP_AREA_STATUS_BROKEN;
            else if(cnf->result == NVRAM_ERRNO_IMAGE_DATA_NOT_SYNC)
                misc_ex_cnf.result.m_u4BPStatus = META_BP_AREA_STATUS_NO_SYNC;
            else{
                misc_ex_cnf.status = FT_CNF_FAIL;
                misc_ex_cnf.result.m_u4BPStatus = cnf->result;
            }
            break;
        }
#endif // end of #if defined(__MOD_NVRAM__)&& defined(__SYSDRV_BACKUP_DISK_RAW__)
        case MSG_ID_NVRAM_SDS_CNF:
        case MSG_ID_NVRAM_BIN_REGION_CNF:
        {
#if !defined(__MODEM_CCCI_EXIST__) || !defined(__MODEM_CARD__)
            if(!Custom_META_SdsSupported())
            {
                misc_ex_cnf.type = FT_MISC_EX_OP_BACKUP_TO_SDS;
                misc_ex_cnf.status = FT_CNF_FAIL;
                misc_ex_cnf.result.m_u4SDSStatus = 0;
            }
            else
#endif
            {
#if !defined(__MODEM_CCCI_EXIST__) || !defined(__MODEM_CARD__)
                nvram_sds_cnf_struct* cnf = (nvram_sds_cnf_struct*)ptrMsgCnf->local_para_ptr;
#else
                nvram_sds_cnf_struct* cnf = (nvram_bin_region_cnf_struct*)ptrMsgCnf->local_para_ptr;               
#endif
                misc_ex_cnf.type = (FT_MISC_EX_CMD_TYPE)cnf->access_id;
                misc_ex_cnf.status = FT_CNF_OK;
                misc_ex_cnf.result.m_u4SDSStatus = cnf->result;
            }
            break;
        }
        default:
            return;
    }
    FT_MISC_EX_SendCnf(&misc_ex_cnf,peer_buff_ret);
}

#if defined(__FS_RAMDISK__)
void FT_Read_RamDisk_Data(ilm_struct *ptrMsg)
{
    FT_MISC_EX_CNF	  misc_ex_cnf; 
    FT_MISC_EX_REQ*   p_req = (FT_MISC_EX_REQ *)ptrMsg->local_para_ptr;
    kal_uint32        u4CurOffset = p_req->cmd.m_u4RamDiskReqOffset;
    kal_uint32        u4TotalSize = ramdisk_get_raw_length();
    // allocate the peer buffer to send to PC-side
    peer_buff_struct *peer_buff = NULL;
    kal_char	*pdu_ptr = NULL;
    kal_uint16	pdu_length = 0;
    kal_uint16  u2_cur_len = FT_MISC_EX_DATA_FRAME_SIZE; // default: 1800 bytes to send

    misc_ex_cnf.type = FT_MISC_EX_OP_RAMDISK_READ;
    misc_ex_cnf.status = FT_CNF_FAIL;  // default value

    misc_ex_cnf.result.m_rRamDiskFrm.m_u4TotalSize = u4TotalSize;
    misc_ex_cnf.result.m_rRamDiskFrm.m_u4CurOffset = u4CurOffset;
    if(u4CurOffset+FT_MISC_EX_DATA_FRAME_SIZE >= u4TotalSize)
    {
        misc_ex_cnf.result.m_rErsDataFrm.m_bLastFrm = true;
        u2_cur_len = u4TotalSize - u4CurOffset;
    }
    else
        misc_ex_cnf.result.m_rErsDataFrm.m_bLastFrm = false;

    // allocate a peer buffer
    if( NULL != (peer_buff=construct_peer_buff(u2_cur_len, 0, 0, TD_CTRL)) ) 
    {
        pdu_ptr = get_peer_buff_pdu( peer_buff, &pdu_length );
        peer_buff->pdu_len = u2_cur_len;
        // read from ram disk
        if(ramdisk_get_raw_data(pdu_ptr, u4CurOffset, u2_cur_len) > 0 || u2_cur_len == 0)
        {
            misc_ex_cnf.status = FT_CNF_OK;
        }
        FT_MISC_EX_SendCnf(&misc_ex_cnf, peer_buff); 
        peer_buff = NULL;// the mem will be released by FT task when copy to TST buffer
    }
    else
    {
        // return fail;
        FT_MISC_EX_SendCnf(&misc_ex_cnf, NULL); 
    }
}
#endif //#if defined(__FS_RAMDISK__)
void FT_MISC_EX_Operation(ilm_struct *ptrMsg)
{
#if defined(__TC01_ERS_SUPPORT__)
    kal_char*             pdu_ptr;
    kal_uint16            pdu_length;
#endif // #if defined(__TC01_ERS_SUPPORT__)
    ilm_struct            ptr_ilm;
    FT_MISC_EX_CNF        misc_ex_cnf;
    memset(&misc_ex_cnf,0x0,sizeof(misc_ex_cnf));
    FT_MISC_EX_REQ*       p_req = (FT_MISC_EX_REQ *)ptrMsg->local_para_ptr;
    peer_buff_struct*     peer_buff_ret = NULL;  // default value

    misc_ex_cnf.type     = p_req->type;
    misc_ex_cnf.status   = FT_CNF_FAIL;
    ft_gl_misc_ex_token  = p_req->header.token;
    switch(p_req->type)
    {
        case FT_MISC_EX_OP_GET_ERS_COUNT:
        {
#if defined(__TC01_ERS_SUPPORT__)
            misc_ex_cnf.result.m_i4ErsDataCount = ERS_query_count(); //wise_query_ERS_count();
#else // #if defined(__TC01_ERS_SUPPORT__)
            misc_ex_cnf.result.m_i4ErsDataCount = 0;
#endif // #if !defined(__TC01_ERS_SUPPORT__)
            misc_ex_cnf.status = FT_CNF_OK;
            break;
        }
        case FT_MISC_EX_OP_GET_ERS_DATA_INFO_BY_INDEX:
        {
#if defined(__TC01_ERS_SUPPORT__)
            ers_info_struct ers_info;
            ERS_query_info(p_req->cmd.m_i4ErsDataIndex, &ers_info);
            misc_ex_cnf.result.m_rErsDataTime.sec = ers_info.ers_ctime.sec;
            misc_ex_cnf.result.m_rErsDataTime.min = ers_info.ers_ctime.min;
            misc_ex_cnf.result.m_rErsDataTime.hour = ers_info.ers_ctime.hour;
            misc_ex_cnf.result.m_rErsDataTime.day = ers_info.ers_ctime.day;
            misc_ex_cnf.result.m_rErsDataTime.mon = ers_info.ers_ctime.mon;
            misc_ex_cnf.result.m_rErsDataTime.wday = ers_info.ers_ctime.wday;
            misc_ex_cnf.result.m_rErsDataTime.year = ers_info.ers_ctime.year;

            if( NULL != (peer_buff_ret=construct_peer_buff((2+1)*2, 0, 0, TD_CTRL)) ) // defined in mcu\external_mmi\wise\bal\sys\include\ws_dbg_type.h
            {
                pdu_ptr = get_peer_buff_pdu( peer_buff_ret, &pdu_length );
                // copy filename
                //kal_mem_cpy(pdu_ptr, (void *)ers_info.ers_filename, (kal_wstrlen(ers_info.ers_filename)+1)*2);
                kal_mem_cpy(pdu_ptr, (void*)&(p_req->cmd.m_i4ErsDataIndex), sizeof(kal_int32));
                kal_mem_set(pdu_ptr+4, 0x0, 2);
                peer_buff_ret->pdu_len = 6; //(kal_wstrlen(ers_info.ers_filename)+1)*2;
            }
            misc_ex_cnf.status = FT_CNF_OK;
#else // #if defined(__TC01_ERS_SUPPORT__)
            misc_ex_cnf.status = FT_CNF_FAIL;
#endif // #if !defined(__TC01_ERS_SUPPORT__)
            break;
        }
        case FT_MISC_EX_OP_GET_ERS_SIZE:
        {
#if defined(__TC01_ERS_SUPPORT__)
            misc_ex_cnf.result.m_u4ErsDataSize = ERS_query_size(); //wise_query_ERS_size();
#else // #if defined(__TC01_ERS_SUPPORT__)
            misc_ex_cnf.result.m_u4ErsDataSize = 0;
#endif // #if !defined(__TC01_ERS_SUPPORT__)
            misc_ex_cnf.status = FT_CNF_OK;
            break;
        }
        case  FT_MISC_EX_OP_GET_ERS_DATA: // send message to NVRAM task to read ERS data
        {
#if defined(__TC01_ERS_SUPPORT__)
            FT_ReadERS_Data(ptrMsg);
            return;
#else // #if defined(__TC01_ERS_SUPPORT__)
            misc_ex_cnf.status = FT_CNF_FAIL;
#endif // #if !defined(__TC01_ERS_SUPPORT__)
            break;
        }

#if defined(__MOD_NVRAM__) && defined(__SYSDRV_BACKUP_DISK_RAW__)
        case FT_MISC_EX_OP_COPY_NVRAM_TO_BP_AREA:
        {
            nvram_create_image_req_struct *ptrMsg;
            FT_ALLOC_OTHER_MSG(&ptr_ilm, sizeof(nvram_create_image_req_struct) );
            ptrMsg = (nvram_create_image_req_struct *)ptr_ilm.local_para_ptr;
            ptrMsg->access_id = (kal_uint8)FT_MISC_EX_OP_COPY_NVRAM_TO_BP_AREA;
            ptrMsg->image_type = NVRAM_IMAGE_TYPE_DEFAULT;
            FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_CREATE_IMAGE_REQ, &ptr_ilm);// wait READ_CNF
            return;
        }
        case FT_MISC_EX_OP_VERIFY_BP_AREA:
        {
            nvram_verify_image_req_struct *ptrMsg;
            FT_ALLOC_OTHER_MSG(&ptr_ilm, sizeof(nvram_verify_image_req_struct) );
            ptrMsg = (nvram_verify_image_req_struct *)ptr_ilm.local_para_ptr;
            ptrMsg->access_id = (kal_uint8)FT_MISC_EX_OP_VERIFY_BP_AREA;
            ptrMsg->image_type = NVRAM_IMAGE_TYPE_DEFAULT;
            ptrMsg->fast_verify =  p_req->cmd.u1BPAreaFastCheck;
            FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_VERIFY_IMAGE_REQ,&ptr_ilm);// wait READ_CNF
            return;
        }
#endif // end of #if defined(__MOD_NVRAM__) && defined(__SYSDRV_BACKUP_DISK_RAW__)
        case FT_MISC_EX_OP_BACKUP_TO_SDS:
        {
#if !defined(__MODEM_CCCI_EXIST__) || !defined(__MODEM_CARD__)
            if(!Custom_META_SdsSupported())
            {
                misc_ex_cnf.status = FT_CNF_FAIL;
                break;
            }
            else
#endif
            {
                nvram_sds_req_struct* ptrMsg;
                FT_ALLOC_OTHER_MSG(&ptr_ilm,sizeof(nvram_sds_req_struct));
                ptrMsg = (nvram_sds_req_struct *)ptr_ilm.local_para_ptr;
                ptrMsg->access_id = (kal_uint8)FT_MISC_EX_OP_BACKUP_TO_SDS;
                // the access mode is defined in nvram_enums.h (nvram_sds_access_enum)
                ptrMsg->access_mode = (nvram_sds_access_enum)p_req->cmd.mode;
#if !defined(__MODEM_CCCI_EXIST__) || !defined(__MODEM_CARD__)
                FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_SDS_REQ, &ptr_ilm);
#else
                FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_BIN_REGION_REQ, &ptr_ilm);
#endif
                return;
            }
        }
        /* ram disk dump */
#if defined(__FS_RAMDISK__)        
        case FT_MISC_EX_OP_RAMDISK_CHECK_EXIST:   /**< \brief check ram disk is existing or not */
        {
            if(ramdisk_is_existed())
            {   
                misc_ex_cnf.result.m_cRamDiskExist = 1;
            }
            else
            {
                misc_ex_cnf.result.m_cRamDiskExist = 0;
            }
            misc_ex_cnf.status = FT_CNF_OK;
            break;
        }
        case FT_MISC_EX_OP_RAMDISK_GET_SIZE:      /**< \brief get ram disk size */
        {
            misc_ex_cnf.result.m_u4RamDiskSize = ramdisk_get_raw_length();
            if(misc_ex_cnf.result.m_u4RamDiskSize != 0)
            {   
                misc_ex_cnf.status = FT_CNF_OK;
            }
            else
            {
                misc_ex_cnf.status = FT_CNF_FAIL;
            }              
            break;
        }
        case FT_MISC_EX_OP_RAMDISK_READ:          /**< \brief read from ram disk */
        {
            FT_Read_RamDisk_Data(ptrMsg);
            return;
        }
#endif //#if defined(__FS_RAMDISK__)        
        case FT_MISC_EX_OP_SET_COMMAND_TO_SYSTEM: /**< \brief set/clr download flag */   
        {
            misc_ex_cnf.status = FT_CNF_OK;
            if(p_req->cmd.m_u4SetCmd2System == 0)  // SET_DL_FLAG = 0   set BROM download flag
            {
                INT_SetCmdToSys(SYS_CMD_SET_BROM_DL);
            }
            else if(p_req->cmd.m_u4SetCmd2System == 1)  // CLR_DL_FLAG = 1   clear download flag
            {
                INT_SetCmdToSys(SYS_CMD_CLR_DL_FLAG);
            }
            else if(p_req->cmd.m_u4SetCmd2System == 2)  //SET_DL_FLAG_BL = 2  set Bootloader download flag
            {
                INT_SetCmdToSys(SYS_CMD_SET_BROM_DL);
            }
            else
            {
                misc_ex_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
        default:
            return;
    }
    FT_MISC_EX_SendCnf(&misc_ex_cnf, peer_buff_ret);
}
kal_uint32 FT_MiscExCheckFunctionSupported(kal_uint32 query_op_code)
{
    kal_uint32 cnf_code;
    if(FT_MISC_EX_OP_END> query_op_code)
    {
        if( query_op_code == FT_MISC_EX_OP_GET_ERS_SIZE ||
                query_op_code == FT_MISC_EX_OP_GET_ERS_DATA
          )
        {
#ifdef WISDOM_MMI
            cnf_code = FT_CNF_OK;
#else
            cnf_code = FT_CNF_FAIL;
#endif

        }
        else if(query_op_code == FT_MISC_EX_OP_COPY_NVRAM_TO_BP_AREA ||
                query_op_code == FT_MISC_EX_OP_VERIFY_BP_AREA
               )
        {
#if defined(__MOD_NVRAM__) && defined(__SYSDRV_BACKUP_DISK_RAW__)
            cnf_codes = FT_CNF_OK;
#else
            cnf_code = FT_CNF_FAIL;
#endif

        }
        else if(query_op_code == FT_MISC_EX_OP_BACKUP_TO_SDS)
        {
#if !defined(__MODEM_CCCI_EXIST__) || !defined(__MODEM_CARD__)
            if(Custom_META_SdsSupported() != KAL_TRUE)
            {
                cnf_code = FT_CNF_FAIL;
            }
            else
#endif
            {
                cnf_code = FT_CNF_OK;
            }
        }
        else if(query_op_code == FT_MISC_EX_OP_RAMDISK_CHECK_EXIST ||
            query_op_code == FT_MISC_EX_OP_RAMDISK_GET_SIZE ||
            query_op_code == FT_MISC_EX_OP_RAMDISK_READ)
        {
#if defined(__FS_RAMDISK__)                  
          cnf_code = FT_CNF_OK;
#else
          cnf_code = FT_CNF_FAIL;
#endif           
        }        
        /*******************************
         * obsoleted op codes
         ******************************/
        else if(query_op_code == FT_MISC_EX_OP_OBSOLETED1 ||
                query_op_code == FT_MISC_EX_OP_OBSOLETED2)
        {
            cnf_code = FT_CNF_FAIL;
        }
        else if(query_op_code == FT_MISC_EX_OP_SET_COMMAND_TO_SYSTEM)
        {
            cnf_code = FT_CNF_OK;
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
