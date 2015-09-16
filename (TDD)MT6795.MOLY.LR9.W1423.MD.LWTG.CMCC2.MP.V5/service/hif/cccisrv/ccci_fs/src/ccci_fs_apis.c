/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   ccci_fs_apis.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI FS APIs
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI FS] Support CCCI FS exception mode.
 *
 * removed!
 * removed!
 * [CCCI FS] Support CCCI FS exception mode.
 *
 * removed!
 * removed!
 * [CCCI FS] Add CCCI FS DL trace log & sequence number between PS & L2
 *
 * removed!
 * removed!
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI & RPC & FS] ASSERT enhancement
 *
 * removed!
 * removed!
 * [CCCI FS] Debug enhancement & Add log.
 *
 * removed!
 * removed!
 * [CCCI FS] Fix CMPT READ API LOG
 *
 * removed!
 * removed!
 * 	modify FindFirst and FindNext maximum value setting
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace (sdio)
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "fs_type.h"
#include "ccci_fs.h"
#include "swla_public.h"
#include "cpu.h"

#define TICK_WRAP    (0xFFFFFFFFUL)

//#define ccci_fs_get_duration(start, end)  (((end) >= (start))? ((end) - (start)): ((TICK_WRAP - (start) + (end) + 1)))

extern kal_uint32 g_ccci_fs_ttc;
extern kal_uint32 g_ccci_fs_ttt[10];
extern kal_uint32 g_ccci_fs_polling[2048];

#define CCCI_FS_FILENAME_SIZE 200
char ccci_fs_filename[CCCI_FS_FILENAME_SIZE];

#define cccifs_quick_trace(...) dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_CCCIFS, ##__VA_ARGS__)

static kal_uint32 CCCI_FS_OP_Wrapper(CCCI_FS_PARA_T* fs_para)
{
    kal_int32 ret = 0;
	//static kal_uint32 polling_cnt = 0;

    if(IS_CCCI_FS_EXCEPTION_MODE())
        g_ccci_fs_int.FS_state = CCCI_FS_EXCEPTION;

  	fs_para->start_time = ccci_fs_get_current_time();
	// Start to trace polling mode
	if (IS_CCCI_FS_POLLING_MODE() || IS_CCCI_FS_EXCEPTION_MODE()){ 
	    g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(fs_para->op_id, CCCI_FS_TRACE_START);
	    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);
	}
    //4 <1> ccci_fs_get_port 
    ret = ccci_fs_get_port(&fs_para->index);
    if(CCCI_SUCCESS != ret){ 
        goto wrapper_exit;
    }
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_GET_PORT_OK, ret, fs_para->index);

    //4 <2> ccci_fs_put_buff
    /*always return CCCI_SUCCESS*/
    ret = ccci_fs_put_buff(fs_para->index, fs_para->op_id, fs_para->pLV_in, fs_para->LV_in_para_cnt);
    if(CCCI_SUCCESS != ret){ 
        ccci_fs_put_port(fs_para->index);
        goto wrapper_exit;
    }
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_PUT_BUF_OK, ret, fs_para->index, fs_para->op_id, fs_para->LV_in_para_cnt);

    //4 <3> ccci_fs_wait_rx
    if (IS_CCCI_FS_POLLING_MODE() || IS_CCCI_FS_NORMAL_MODE())
        ccci_fs_wait_rx(fs_para->index);
    if(IS_CCCI_FS_EXCEPTION_MODE())
        ccci_fs_wait_rx_exception(fs_para->index);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_WAIT_RX_OK, fs_para->index);
    
    //4 <4> ccci_fs_get_buff
    /*always return CCCI_SUCCESS*/
    ret = ccci_fs_get_buff(fs_para->index, fs_para->op_id, fs_para->pLV_out, &fs_para->LV_out_para_cnt);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_GET_BUF_OK, ret, fs_para->index, fs_para->op_id, fs_para->LV_out_para_cnt);
    
    //4 <5> ccci_fs_put_port
    /*always return CCCI_SUCCESS*/
    ret = ccci_fs_put_port(fs_para->index); 
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_PUT_PORT_OK, ret, fs_para->index);
		
	// Accumulate wait ap time
	fs_para->end_time = ccci_fs_get_current_time();
    fs_para->duration = ccci_fs_get_duration(fs_para->start_time, fs_para->end_time);
    fs_para->us       = fs_para->duration;

	// Start to trace polling mode
	if (IS_CCCI_FS_POLLING_MODE() || IS_CCCI_FS_EXCEPTION_MODE()){ 
	    g_ccci_fs_int.wait_ap_time_polling += fs_para->duration;
	    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_WAIT_TIME_POLLING, (void *)&g_ccci_fs_int.wait_ap_time_polling);

	    g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(fs_para->op_id, CCCI_FS_TRACE_END);
	    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);
	}
	else{
        g_ccci_fs_ttt[fs_para->index] += fs_para->duration;
		fs_para->total_tick = g_ccci_fs_ttt[fs_para->index];
        CCCI_FS_ADD_CARRY(g_ccci_fs_int.wait_ap_time_normal, fs_para->duration, g_ccci_fs_int.wait_ap_time_normal_carry);
	    g_ccci_fs_int.wait_ap_time_normal += fs_para->duration;
	    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_WAIT_TIME_NORMAL_CARRY, (void *)&g_ccci_fs_int.wait_ap_time_normal_carry);
        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_WAIT_TIME_NORMAL, (void *)&g_ccci_fs_int.wait_ap_time_normal);
	}
    g_ccci_fs_ttc++;
    wrapper_exit:
    //SLA_CustomLogging("CF1", SA_stop);
    if(CCCI_SUCCESS != ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_RET_ERR, ret, fs_para->index);
    }else{          
        //ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_RET_OK, ret, fs_para->index);
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_RET_OK, g_ccci_fs_ttc,fs_para->op_id,ret,fs_para->index,fs_para->us,fs_para->total_tick,fs_para->start_time,fs_para->end_time,fs_para->duration);
    }
   
    return ret;

}

kal_int32 MD_FS_CMPT_Read(const WCHAR * FileName, NVRAM_FS_PARAM_CMPT_T* nvram_param)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    CCCI_FS_PARA_T  ccci_fs_paras;
    void *user_data_ptr = 0x0;
    
	SLA_CustomLogging("Z22", SA_start);   
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OPEN_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FileName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS CMPT_Read] filename: %s",ccci_fs_filename); 

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CMPTREAD_IN);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CMPTREAD_USER_INPUT,\
            nvram_param->opid_map, nvram_param->Flag   ,nvram_param->Offset, \
            nvram_param->Whence  , nvram_param->Length);

    /* AP CCCI FS input parameters */
    if(nvram_param->Length > FS_CCCI_MAX_USER_BUFF)
    {
        nvram_param->Length = FS_CCCI_MAX_USER_BUFF;
    }
    /* FileName */
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FileName;
    LV_in[LV_in_num].len = sizeof(NVRAM_FS_PARAM_CMPT_T) ;
    LV_in[LV_in_num++].val = nvram_param;

    //Do operation valid check: opid bitmap shall contain open/close at least
    if ( ((nvram_param->opid_map & NVRAM_FS_CMPT_OPEN)== 0) || ((nvram_param->opid_map & NVRAM_FS_CMPT_CLOSE) == 0) )
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_API, CCCIFS_TR_CMPTREAD_OPIDMAP_ERR, nvram_param->opid_map);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, 0,nvram_param->opid_map,0,0, 0, __LINE__);
    }

    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_uint32) + sizeof(kal_uint32);  // AP will relpy two return value, first for OPID, second for error code
    LV_out[LV_out_num++].val = nvram_param->ret;

    // File Size
    LV_out[LV_out_num].len = sizeof(kal_uint32);
    LV_out[LV_out_num++].val = nvram_param->FileSize;
    // Read Byte
    LV_out[LV_out_num].len = sizeof(kal_uint32);
    LV_out[LV_out_num++].val = nvram_param->Read;
    // DataPtr
    LV_out[LV_out_num].len = nvram_param->Length;
    LV_out[LV_out_num++].val = nvram_param->DataPtr; 

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_CMPTREAD;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
      // Print user's first data value to help debugging
      user_data_ptr = (void *)((((kal_uint32)LV_out[3].val  + 3) >> 2) << 2);
      ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CMPTREAD_RET,\
            LV_out[0].len, *((kal_uint32*)LV_out[0].val), *((kal_uint32*)LV_out[0].val+1),\
            LV_out[1].len, *((kal_uint32*)LV_out[1].val),\
            LV_out[2].len, *((kal_uint32*)LV_out[2].val),\
            LV_out[3].len, *((kal_uint32*)user_data_ptr));
        ret = nvram_param->ret[1];
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CMPTREAD_OUT);
	SLA_CustomLogging("Z22", SA_stop);    
    return ret;
}

static kal_bool DSP_OPEN = KAL_FALSE;

/*!
 * @function        1.MD_FS_Open
 * @brief           Open file API
 *
 * @param FileName  [IN] file name
 * @param Flag      [IN] flag
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Open(const WCHAR * FileName, kal_uint32 Flag)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

	SLA_CustomLogging("Z01", SA_start);    
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OPEN_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FileName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS Open] filename: %s",ccci_fs_filename);
    if(FileName[0] == 0x57) //W
    {
        cccifs_quick_trace("[CCCI_FS] DSP OPEN..");
        SLA_CustomLogging("DPO",SA_label);
        DSP_OPEN = KAL_TRUE;
    }

    /* AP CCCI FS input parameters */
        /* FileName */
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FileName;
        /* Flag */
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Flag;

    /* AP CCCI FS output value */
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret; /* AP side return value */

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_OPEN;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);


    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OPEN_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val) );
        ret = ap_op_ret;
    }

    cccifs_quick_trace("[CCCIFS] DSP OPEN..%s", FileName);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OPEN_OUT);
	SLA_CustomLogging("Z01", SA_stop);    
    return ret;
}

/*!
 * @function        2.MD_FS_OpenHint
 * @brief           Open a file with location hint to reduce the search time. 
 *                  DSR_Hint is no use in EMCS_FS
 *
 * @param FileName  [IN] file name
 * @param Flag      [IN] flag
 * @param DSR_Hint  [IN] no use in EMCS_FS, AP just echo this value back to MD
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_OpenHint(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

	SLA_CustomLogging("Z11", SA_start);    
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OPENHINT_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FileName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS OpenHint] filename: %s",ccci_fs_filename);
    /* AP CCCI FS input parameters */
    // FileName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FileName;
    // Flag
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Flag;
    // DSR_Hint
    LV_in[LV_in_num].len = sizeof(FS_FileOpenHint);
    LV_in[LV_in_num++].val = (void *)DSR_Hint;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // DSR_Hint
    LV_out[LV_out_num].len = sizeof(FS_FileOpenHint);
    LV_out[LV_out_num++].val = (void *)DSR_Hint;    /*always return CCCI_SUCCESS*/

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_OPENHINT;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OPENHINT_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val), LV_out[1].len, *((kal_uint32*)LV_out[1].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OPENHINT_OUT);
	SLA_CustomLogging("Z11", SA_stop);        
    return ret;

}

/*!
 * @function        3.MD_FS_Close
 * @brief           close file handle
 *
 * @param FileHandle [IN] file handle
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Close(FS_HANDLE FileHandle)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

	SLA_CustomLogging("Z05", SA_start);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLOSE_IN);

    if(DSP_OPEN == KAL_TRUE)
    {
        cccifs_quick_trace("[CCCI_FS] DSP CLOSE..");
        SLA_CustomLogging("DPC",SA_label);
        DSP_OPEN = KAL_FALSE;
    }

    /* AP CCCI FS input parameters */
    // File Handle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&FileHandle;

    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_CLOSE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLOSE_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLOSE_OUT);
   	SLA_CustomLogging("Z05", SA_stop);
    return ret;
}

/*!
 * @function        4.MD_FS_Read
 * @brief           read from file handle
 *
 * @param FileHandle [IN] file handle
 * @param DataPtr    [IN] Read data buffer pointer
 * @param Length     [IN] Read length
 * @param Read       [IN] 
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Read(FS_HANDLE FileHandle, void *DataPtr, kal_uint32 Length, kal_uint32 *Read)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;
    void *user_data_ptr = 0x0;
    
	SLA_CustomLogging("Z03", SA_start);    
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_READ_IN);

    /* AP CCCI FS input parameters */
    // FileHandle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&FileHandle;
    // Length
    if(Length > FS_CCCI_MAX_USER_BUFF)
    {
        Length = FS_CCCI_MAX_USER_BUFF;
    }
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Length;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // Read Byte
    LV_out[LV_out_num].len = sizeof(kal_uint32);
    LV_out[LV_out_num++].val = Read;
    // DataPtr
    LV_out[LV_out_num].len = Length;
    LV_out[LV_out_num++].val = DataPtr;    

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_READ;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        // Print user's first data value to help debugging
        user_data_ptr = (void *)((((kal_uint32)LV_out[2].val  + 3) >> 2) << 2);
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_READ_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val),\
            LV_out[1].len, *((kal_uint32*)LV_out[1].val),LV_out[2].len, *((kal_uint32*)user_data_ptr));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_READ_OUT);
	SLA_CustomLogging("Z03", SA_stop);    
    return ret;

}

/*!
 * @function        5.MD_FS_Write
 * @brief           close file handle
 *
 * @param FileHandle [IN] file handle
 * @param DataPtr    [IN] Write data buffer pointer
 * @param Length     [IN] Write length
 * @param Written    [IN] Byte written 
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Write(FS_HANDLE FileHandle, void *DataPtr, kal_uint32 Length, kal_uint32 *Written)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

	SLA_CustomLogging("Z04", SA_start);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRITE_IN);

    /* AP CCCI FS input parameters */
    // FileHandle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&FileHandle;
    if(Length > FS_CCCI_MAX_USER_BUFF)
    {
        Length = FS_CCCI_MAX_USER_BUFF;
    }
    // DataPtr
    LV_in[LV_in_num].len = Length;
    LV_in[LV_in_num++].val = DataPtr;
    // Length
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Length;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // Written Bytes
    LV_out[LV_out_num].len = sizeof(kal_uint32);
    LV_out[LV_out_num++].val = Written;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_WRITE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRITE_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val),\
            LV_out[1].len, *((kal_uint32*)LV_out[1].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRITE_OUT);
  	SLA_CustomLogging("Z04", SA_stop);
    return ret;
}

/*!
 * @function        6.MD_FS_Seek
 * @brief           FS seek function
 *
 * @param FileHandle [IN] file handle
 * @param Offset     [IN] Seek offset
 * @param Whence     [IN] 
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Seek(FS_HANDLE FileHandle, kal_int32 Offset, kal_int32 Whence)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

	SLA_CustomLogging("Z02", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_SEEK_IN);

    /* AP CCCI FS input parameters */
    // FileHandle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&FileHandle;
    // DataPtr
    LV_in[LV_in_num].len = sizeof(kal_int32);
    LV_in[LV_in_num++].val = (void *)&Offset;
    // Length
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Whence;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_SEEK;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_SEEK_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_SEEK_OUT);
   	SLA_CustomLogging("Z02", SA_stop);
    return ret;
}

/*!
 * @function        7.MD_FS_GetFileSize
 * @brief           FS get file size
 *
 * @param FileHandle [IN] file handle
 * @param Size       [IN] return size
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 *Size)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

   	SLA_CustomLogging("Z09", SA_start);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETFSZ_IN);

    /* AP CCCI FS input parameters */
    // FileHandle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&FileHandle;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // Size
    LV_out[LV_out_num].len = sizeof(kal_uint32);
    LV_out[LV_out_num++].val = (void *)Size;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_GETFILESIZE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETFSZ_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val),\
            LV_out[1].len, *((kal_uint32*)LV_out[1].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETFSZ_OUT);
   	SLA_CustomLogging("Z09", SA_stop);
    return ret;
}

/*!
 * @function        8.MD_FS_Delete
 * @brief           Delete a file by name
 *
 * @param FileName [IN] file name
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Delete(const WCHAR *FileName)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

   	SLA_CustomLogging("Z0F", SA_start);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_DEL_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FileName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS Delete] filename: %s",ccci_fs_filename);
    /* AP CCCI FS input parameters */
    //FileName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FileName;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_DELETE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_DEL_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_DEL_OUT);
   	SLA_CustomLogging("Z0F", SA_stop);    
    return ret;
}

/*!
 * @function        9.MD_FS_GetAttributes
 * @brief           Get file attributes by name
 *
 * @param FileName [IN] file name
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_GetAttributes(const WCHAR * FileName)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

   	SLA_CustomLogging("Z10", SA_start);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GATT_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FileName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS GetAttributes] filename: %s",ccci_fs_filename);
    /* AP CCCI FS input parameters */
    //FileName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FileName;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_GETATTRIBUTES;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GATT_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GATT_OUT);
   	SLA_CustomLogging("Z10", SA_stop);
    return ret;
}

/*!
 * @function        10.MD_FS_CreateDir
 * @brief           Create directory by name
 *
 * @param DirName [IN] directory name
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_CreateDir(const WCHAR * DirName)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

   	SLA_CustomLogging("Z07", SA_start);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_MKDIR_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)DirName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS CreateDir] filename: %s",ccci_fs_filename);

    /* AP CCCI FS input parameters */
    //DirName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)DirName;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_CREATEDIR;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_MKDIR_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_MKDIR_OUT);
   	SLA_CustomLogging("Z07", SA_stop);
    return ret;
}

/*!
 * @function        11.MD_FS_RemoveDir
 * @brief           Remove directory by name
 *
 * @param DirName [IN] directory name
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_RemoveDir(const WCHAR * DirName)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

   	SLA_CustomLogging("Z08", SA_start);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_RMDIR_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)DirName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS RemoveDir] filename: %s",ccci_fs_filename);

    /* AP CCCI FS input parameters */
    //DirName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)DirName;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_REMOVEDIR;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_RMDIR_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_RMDIR_OUT);
   	SLA_CustomLogging("Z08", SA_stop);
    return ret;
}

/*!
 * @function        12.MD_FS_GetFolderSize
 * @brief           Get folder size
 *
 * @param DirName [IN] directory name
 * @param Flag    [IN] flag
 * @param RecursiveStack    [IN] 
 * @param StackSize    [IN] 
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_GetFolderSize(const WCHAR *DirName, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

    SLA_CustomLogging("Z0A", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GDSZ_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)DirName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS GetFolderSize] filename: %s",ccci_fs_filename);
    /* AP CCCI FS input parameters */
    //DirName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)DirName;
    // Flag
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Flag;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_GETFOLDERSIZE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GDSZ_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GDSZ_OUT);
    SLA_CustomLogging("Z0A", SA_stop);
    return ret;
}

/*!
 * @function        13.MD_FS_Rename
 * @brief           Get folder size
 *
 * @param FileName [IN] file name
 * @param NewName  [IN] new file name
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Rename(const WCHAR * FileName, const WCHAR * NewName)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;
    SLA_CustomLogging("Z0B", SA_start);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSRENAME_IN);
   kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FileName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS Rename Old] filename: %s",ccci_fs_filename);

    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)NewName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS Rename New] filename: %s",ccci_fs_filename);
    /* AP CCCI FS input parameters */
    //FileName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FileName;
    // NewName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)NewName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)NewName;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_RENAME;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSRENAME_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSRENAME_OUT);
        SLA_CustomLogging("Z0B", SA_stop);
    return ret;
}

/*!
 * @function        14.MD_FS_Move
 * @brief           Move
 *
 * @param SrcFullPath [IN] src file name
 * @param DstFullPath [IN] dst file name
 * @param Flag        [IN] 
 * @param Progress    [IN] 
 * @param RecursiveStack [IN] 
 * @param StackSize   [IN] 
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

        SLA_CustomLogging("Z0C", SA_stop);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSMV_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)SrcFullPath,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS Move Src] filename: %s",ccci_fs_filename);

    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)DstFullPath,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS Move Dst] filename: %s",ccci_fs_filename);

    /* AP CCCI FS input parameters */
    //SrcFullPath
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)SrcFullPath) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)SrcFullPath;
    // DstFullPath
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)DstFullPath) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)DstFullPath;
    // Flag
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Flag;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_MOVE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSMV_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSMV_OUT);
            SLA_CustomLogging("Z0C", SA_stop);
    return ret;
}

/*!
 * @function        15.MD_FS_Count
 * @brief           Count
 *
 * @param FullPath    [IN] path
 * @param Flag        [IN] dst file name
 * @param RecursiveStack [IN]
 * @param StackSize   [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Count(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;


        SLA_CustomLogging("Z0D", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSCNT_IN);

    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FullPath,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS Count] filename: %s",ccci_fs_filename);

    /* AP CCCI FS input parameters */
    //FullPath
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FullPath) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FullPath;
    // Flag
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Flag;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_COUNT;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSCNT_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FSCNT_OUT);
        SLA_CustomLogging("Z0D", SA_stop);
    return ret;
}

/*!
 * @function        16.MD_FS_XDelete
 * @brief           XDelete
 *
 * @param FullPath    [IN] path
 * @param Flag        [IN] dst file name
 * @param RecursiveStack [IN]
 * @param StackSize   [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_XDelete(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

        SLA_CustomLogging("Z18", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_XDEL_IN);
    
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FullPath,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS XDelete] filename: %s",ccci_fs_filename);

    /* AP CCCI FS input parameters */
    //FullPath
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FullPath) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FullPath;
    // Flag
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Flag;

    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_XDELETE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_XDEL_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_XDEL_OUT);
        SLA_CustomLogging("Z18", SA_stop);    
    return ret;
}

/*!
 * @function        17.MD_FS_FindFirst
 * @brief           Find First
 *
 * @param NamePattern    [IN] pattern
 * @param Attr           [IN] file attribute
 * @param AttrMask       [IN]
 * @param FileInfo       [IN]
 * @param FileName       [IN] 
 * @param MaxLength      [IN] 
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_FindFirst(const WCHAR * NamePattern, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;
    //kal_int32 MaxLength_nonWCHAR = MaxLength/2 -1;
    kal_int32 MaxLength_nonWCHAR = MaxLength/2;     //length shall include '\0'

        SLA_CustomLogging("Z12", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDFST_IN);
    
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)NamePattern,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS FindFirst NamePattern] filename: %s",ccci_fs_filename);

    /* AP CCCI FS input parameters */
    //NamePattern
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)NamePattern) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)NamePattern;
    // Attr
    LV_in[LV_in_num].len = sizeof(kal_uint8);
    LV_in[LV_in_num++].val = (void *)&Attr;
    // AttrMask
    LV_in[LV_in_num].len = sizeof(kal_uint8);
    LV_in[LV_in_num++].val = (void *)&AttrMask;
    // MaxLength //AP return length = (MaxLength+1)*2; !!! for WCHAR !!!!
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    //LV_in[LV_in_num++].val = (void *)&MaxLength;
    LV_in[LV_in_num++].val = (void *)&MaxLength_nonWCHAR;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // FileInfo
    LV_out[LV_out_num].len = sizeof(FS_DOSDirEntry);
    LV_out[LV_out_num++].val = (void *)FileInfo;
    // FileName
    LV_out[LV_out_num].len = MaxLength;
    LV_out[LV_out_num++].val = (void *)FileName;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_FINDFIRST;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDFST_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val),\
            LV_out[1].len, *((kal_uint32*)LV_out[1].val),LV_out[2].len, *((kal_uint32*)LV_out[2].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDFST_OUT);

            SLA_CustomLogging("Z12", SA_stop);
    return ret;
}

/*!
 * @function        18.MD_FS_FindNext
 * @brief           Find Next
 *
 * @param FileHandle     [IN] file handle
 * @param FileInfo       [IN] 
 * @param FileName       [IN]
 * @param MaxLength      [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;
    //kal_int32 MaxLength_nonWCHAR = MaxLength/2 -1;
    kal_int32 MaxLength_nonWCHAR = MaxLength/2;     //length shall include '\0'

        SLA_CustomLogging("Z13", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDNXT_IN);

    /* AP CCCI FS input parameters */
    //FileHandle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&FileHandle;
    // MaxLength //AP return length = (MaxLength+1)*2; !!! for WCHAR !!!!
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    //LV_in[LV_in_num++].val = (void *)&MaxLength;
    LV_in[LV_in_num++].val = (void *)&MaxLength_nonWCHAR;
    
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // FileInfo
    LV_out[LV_out_num].len = sizeof(FS_DOSDirEntry);
    LV_out[LV_out_num++].val = (void *)FileInfo;
    // FileName
    LV_out[LV_out_num].len = MaxLength;
    LV_out[LV_out_num++].val = (void *)FileName;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_FINDNEXT;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDNXT_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val),\
            LV_out[1].len, *((kal_uint32*)LV_out[1].val),LV_out[2].len, *((kal_uint32*)LV_out[2].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDNXT_OUT);
            SLA_CustomLogging("Z13", SA_stop);
    return ret;
}

/*!
 * @function        19.MD_FS_FindClose
 * @brief           Find Close
 *
 * @param FileHandle     [IN] file handle
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_FindClose(FS_HANDLE FileHandle)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

        SLA_CustomLogging("Z14", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDCLS_IN);

    /* AP CCCI FS input parameters */
    //FileHandle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&FileHandle;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_FINDCLOSE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDCLS_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_FNDCLS_OUT);
            SLA_CustomLogging("Z14", SA_stop);
    return ret;
}

/*!
 * @function        20.MD_FS_GetDrive
 * @brief           Get Driver
 *
 * @param Type     [IN]
 * @param Serial   [IN]
 * @param AltMask  [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_GetDrive(kal_uint32 Type, kal_uint32 Serial, kal_uint32 AltMask)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

            SLA_CustomLogging("Z1A", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETDRV_IN);

    /* AP CCCI FS input parameters */
    //Type
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Type;
    //Serial
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Serial;
    //AltMask
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&AltMask;

    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_GETDRIVE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETDRV_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETDRV_OUT);
            SLA_CustomLogging("Z1A", SA_stop);
    return ret;
}

/*!
 * @function        21.MD_FS_GetClusterSize
 * @brief           Get cluster size
 *
 * @param DriveIdx [IN] drive index, EMCS_FSD only reply DriveIdx == 'Z'
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_GetClusterSize(kal_uint32 DriveIdx)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

            SLA_CustomLogging("Z1B", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETCLUSZ_IN);

    /* AP CCCI FS input parameters */
    //DriveIdx
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&DriveIdx;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_GETCLUSTERSIZE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETCLUSZ_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETCLUSZ_OUT);
            SLA_CustomLogging("Z1B", SA_stop);
    return ret;
}

/*!
 * @function        22.MD_FS_SetDiskFlag
 * @brief           Set Disk Flag
 *
 * @param void
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_SetDiskFlag(void)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;
            SLA_CustomLogging("Z1C", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_SETDKFG_IN);

    /* AP CCCI FS input parameters */
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_SETDISKFLAG;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_SETDKFG_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_SETDKFG_OUT);
            SLA_CustomLogging("Z1C", SA_stop);
    return ret;
}

/*!
 * @function        23.MD_FS_CloseAll
 * @brief           FS close all
 *
 * @param void
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_CloseAll(void)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

            SLA_CustomLogging("Z06", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLOSEALL_IN);

    /* AP CCCI FS input parameters */
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_CLOSEALL;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLOSEALL_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLOSEALL_OUT);
            SLA_CustomLogging("Z06", SA_stop);
    return ret;
}

/*!
 * @function        24.MD_FS_ClearDiskFlag
 * @brief           FS clear disk flag
 *
 * @param void
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_ClearDiskFlag(void)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;


            SLA_CustomLogging("Z19", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLRDISKFG_IN);

    /* AP CCCI FS input parameters */
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_CLEARDISKFLAG;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLRDISKFG_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_CLRDISKFG_OUT);
            SLA_CustomLogging("Z19", SA_stop);
    return ret;
}

/*!
 * @function        25.MD_FS_GetDiskInfo
 * @brief           FS get disk Info
 *
 * @param DriveName [IN]
 * @param DiskInfo  [IN]
 * @param Flags     [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_GetDiskInfo(const WCHAR *DriveName, FS_DiskInfo *DiskInfo, kal_int32 Flags)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;
    FS_DiskInfo *ap_ret_fdinfo;

            SLA_CustomLogging("Z0E", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETDKINFO_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)DriveName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS GetDiskInfo] filename: %s",ccci_fs_filename);
    /* AP CCCI FS input parameters */
    // DriveName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)DriveName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)DriveName;
    // Flags
    LV_in[LV_in_num].len = sizeof(kal_int32);
    LV_in[LV_in_num++].val = (void *)&Flags;
    
        /* AP CCCI FS return value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // DiskInfo
    LV_out[LV_out_num].len = sizeof(FS_DiskInfo);
    LV_out[LV_out_num++].val = (void *)DiskInfo;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_GETDISKINFO;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETDKINFO_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val), LV_out[1].len, *((kal_uint32*)LV_out[1].val));
        ap_ret_fdinfo = (FS_DiskInfo *)LV_out[1].val;
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_IT_GETDKINFO_AP_TRACE, ap_ret_fdinfo->SectorsPerCluster, ap_ret_fdinfo->TotalClusters, ap_ret_fdinfo->FreeClusters, ret);
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_GETDKINFO_OUT);
            SLA_CustomLogging("Z0E", SA_stop);
    return ret;
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
/* under construction !*/
#endif 
}

/*!
 * @function        26.MD_FS_ShutDown
 * @brief           FS shutdown
 *
 * @param void
 *
 * @return          void         
 *
 */
void MD_FS_ShutDown(void)
{   
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

            SLA_CustomLogging("Z17", SA_start);

            
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_SHUTDN_IN);

    /* AP CCCI FS input parameters */
    /* AP CCCI FS output value */

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_SHUTDOWN;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_SHUTDN_OUT);
            SLA_CustomLogging("Z17", SA_stop);
    return;
}

/*!
 * @function        27.MD_FS_UnlockAll
 * @brief           FS unlock all
 *
 * @param void
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_UnlockAll(void)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_ULKALL_IN);

    /* AP CCCI FS input parameters */
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_UNLOCKALL;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_ULKALL_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_ULKALL_OUT);
    return ret; 
}

/*!
 * @function        28.MD_FS_LockFAT
 * @brief           FS lock FAT
 *
 * @param Type     [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_LockFAT(kal_uint32 Type)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_LKFAT_IN);

    /* AP CCCI FS input parameters */
    //Type
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Type;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_LOCKFAT;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_LKFAT_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_LKFAT_OUT);
    return ret;
}

/*!
 * @function        29.MD_FS_OTPWrite
 * @brief           FS OTP Write
 *
 * @param devtype   [IN]
 * @param Offset    [IN]
 * @param BufferPtr [IN]
 * @param Length    [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_OTPWrite(kal_int32 devtype, kal_uint32 Offset, void *BufferPtr, kal_uint32 Length)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPWR_IN);

    /* AP CCCI FS input parameters */
    // FileHandle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&devtype;
    // Offset
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Offset;
    // DataPtr
    LV_in[LV_in_num].len = Length;
    LV_in[LV_in_num++].val = BufferPtr;
    // Length
    if(Length > FS_CCCI_MAX_USER_BUFF)
    {
        Length = FS_CCCI_MAX_USER_BUFF;
    }
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Length;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_OTPWRITE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPWR_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPWR_OUT);
    return ret;
}

/*!
 * @function        30.MD_FS_OTPRead
 * @brief           FS OTP Read
 *
 * @param devtype   [IN]
 * @param Offset    [IN]
 * @param BufferPtr [IN]
 * @param Length    [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_OTPRead(kal_int32 devtype, kal_uint32 Offset, void *BufferPtr, kal_uint32 Length)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPRD_IN);

    /* AP CCCI FS input parameters */
    // FileHandle
    LV_in[LV_in_num].len = sizeof(FS_HANDLE);
    LV_in[LV_in_num++].val = (void *)&devtype;
    // Offset
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Offset;
    // Length
    if(Length > FS_CCCI_MAX_USER_BUFF)
    {
        Length = FS_CCCI_MAX_USER_BUFF;
    }
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Length;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // BufferPtr
    LV_out[LV_out_num].len = Length;
    LV_out[LV_out_num++].val = BufferPtr;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_OTPREAD;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPRD_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val),\
            LV_out[1].len, *((kal_uint32*)LV_out[1].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPRD_OUT);
    return ret;
}

/*!
 * @function        31.MD_FS_OTPQueryLength
 * @brief           FS OTP Read
 *
 * @param devtype   [IN]
 * @param Length    [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_OTPQueryLength(kal_int32 devtype, kal_uint32 *Length)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPQLEN_IN);

    /* AP CCCI FS input parameters */
    // devtype
    LV_in[LV_in_num].len = sizeof(kal_int32);
    LV_in[LV_in_num++].val = (void *)&devtype;

    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;
    // return length 
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)Length;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_OTPQUERYLENGTH;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPQLEN_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val),\
            LV_out[1].len, *((kal_uint32*)LV_out[1].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPQLEN_OUT);
    return ret;
}

/*!
 * @function        32.MD_FS_OTPLock
 * @brief           FS OTP Read
 *
 * @param devtype   [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_OTPLock(kal_int32 devtype)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPLK_IN);

    /* AP CCCI FS input parameters */
    // Type
    LV_in[LV_in_num].len = sizeof(kal_int32);
    LV_in[LV_in_num++].val = (void *)&devtype;
    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_OTPLOCK;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPLK_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPLK_OUT);
    return ret;
}

/*!
 * @function        33.MD_FS_Restore
 * @brief           FS OTP Read
 *
 * @param FileName [IN]
 * @param pBuffer  [IN]
 * @param Length   [IN]
 *
 * @return          
 *                  AP response:            PASS
 *                  CCCI_FAIL:              NG
 */
kal_int32 MD_FS_Restore(const WCHAR *FileName, void *pBuffer, kal_uint32 Length)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV_in[FS_CCCI_MAX_ARG_NUM];
    FS_CCCI_LV_T LV_out[FS_CCCI_MAX_ARG_NUM];
    kal_uint32 LV_in_num = 0;
    kal_uint32 LV_out_num = 0;
    kal_int32 ret;
    kal_int32 ap_op_ret = 0;
    CCCI_FS_PARA_T  ccci_fs_paras;

            SLA_CustomLogging("Z21", SA_start);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPRSTORE_IN);
    kal_mem_set(ccci_fs_filename, 0 , CCCI_FS_FILENAME_SIZE);
    kal_dchar2char((WCHAR *)FileName,ccci_fs_filename);
    cccifs_quick_trace("[CCCI_FS Restore] filename: %s",ccci_fs_filename);
    /* AP CCCI FS input parameters */
    // FileName
    LV_in[LV_in_num].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
    LV_in[LV_in_num++].val = (void *)FileName;
    // pBuffer
    LV_in[LV_in_num].len = Length;
    LV_in[LV_in_num++].val = (void *)pBuffer;
    // Length
    LV_in[LV_in_num].len = sizeof(kal_uint32);
    LV_in[LV_in_num++].val = (void *)&Length;

    /* AP CCCI FS output value */
    // return code
    LV_out[LV_out_num].len = sizeof(kal_int32);
    LV_out[LV_out_num++].val = (void *)&ap_op_ret;

    ccci_fs_paras.index = index;
    ccci_fs_paras.op_id = FS_CCCI_OP_RESTORE;
    ccci_fs_paras.pLV_in = LV_in;
    ccci_fs_paras.LV_in_para_cnt = LV_in_num;
    ccci_fs_paras.pLV_out = LV_out;
    ccci_fs_paras.LV_out_para_cnt = LV_out_num;

    ret = CCCI_FS_OP_Wrapper(&ccci_fs_paras);

    if(CCCI_SUCCESS == ret){ 
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPRSTORE_RET, LV_out[0].len, *((kal_uint32*)LV_out[0].val));
        ret = ap_op_ret;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_OTPRSTORE_OUT);
            SLA_CustomLogging("Z21", SA_stop);
    return ret;
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
