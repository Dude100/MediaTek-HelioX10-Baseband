
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ccci_sysmsg_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implements the CCCI_SYS_MSG IT functions for CCCI IT framework.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 *
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/
//#include "ccci_rpc_common.h"
//#include "ccci_rpc_data.h"
#include "kal_debug.h"
#include "ccci_if.h"
#include "dhl_trace.h"

#ifdef __CCCI_IT_CTRL__
#include "ccci_it_ctrl_if.h"

/*******************************************************************************
 * Define macro
 *******************************************************************************/
//#define CCCI_SYSMSG_IT_DBG(_f,...) dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_CCCI_IT_CTRL, "[CCCI_SYSMSG_IT] %s %d: "_f, __FUNCTION__, __LINE__  , ##__VA_ARGS__);
#define CCCI_SYSMSG_IT_DBG(...) dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_CCCI_IT_CTRL, ##__VA_ARGS__)

#define INVALID_RESULT (0xFFFFFFFF)
#define TEST_DATA   (0x77885566)
#define RESULT_LP_OK   (0x1234)
#define RESULT_LP_NOK  (0x4321)
#define MSG_ID_TEST_MD2AP (0x113)         //Notes: need to sync with AP side, hard code it
#define MSG_ID_TEST_AP2MD (0x1FF)         //Notes: need to sync with AP side, hard code it

/*******************************************************************************
 * Define functions.
 *******************************************************************************/
kal_uint32 sys_msg_result = INVALID_RESULT;
kal_uint32 tmp_result = 0;
//use eemcs sysmsg do it 
kal_bool eemcs_sysmsg_it(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

    CCCI_SYSMSG_IT_DBG("[CCCI_SYSMSG_IT] Send sys_message");
    ccci_send_message(MSG_ID_TEST_MD2AP, TEST_DATA);
    //ccci_send_message(CCMSG_ID_SYSMSGSVC_L1_QUERY_AP_VOLTAGE, 0);    //for testing
    return KAL_TRUE;

}

void eemcs_sysmsg_it_check_echo_result(kal_uint32 param)
{
    CCCI_SYSMSG_IT_DBG("[CCCI_SYSMSG_IT] Get result from AP : %d", param);
    tmp_result = param;   //save the result and we can use CVD to watch this value
    if(param == TEST_DATA)
    {
        sys_msg_result = RESULT_LP_OK;
    }
    else
    {
        sys_msg_result = RESULT_LP_NOK;
    }
}

kal_bool eemcs_sysmsg_it_check_echo_result_PASS(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    if(sys_msg_result == RESULT_LP_OK)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

kal_bool eemcs_sysmsg_it_check_echo_result_FAILED(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    if(sys_msg_result == RESULT_LP_NOK)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

kal_bool eemcs_sysmsg_it_reset_result(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    sys_msg_result = INVALID_RESULT;
    return KAL_FALSE;
}

//AT+CCCI_SYSMSG=1,2,3...
IT_MODE_T ccci_sysmsg_it_mode_table[] = {    
    {"eemcs_sysmsg_it",                      eemcs_sysmsg_it,                              NULL},
    {"eemcs_sysmsg_it_check_result_PASS",    eemcs_sysmsg_it_check_echo_result_PASS,       NULL},
    {"eemcs_sysmsg_it_check_result_FAIL",    eemcs_sysmsg_it_check_echo_result_FAILED,     NULL},
    {"eemcs_sysmsg_it_reset_result"     ,    eemcs_sysmsg_it_reset_result            ,     NULL},    
        
};

kal_bool ccci_sysmsg_it_create(){

    ccci_register_sysmsgsvc_callback(MSG_ID_TEST_AP2MD, eemcs_sysmsg_it_check_echo_result);
    return ccci_it_mode_control_table_reg("CCCI_SYSMSG", 
                                          ccci_sysmsg_it_mode_table, 
                                          sizeof(ccci_sysmsg_it_mode_table) / sizeof(IT_MODE_T) 
                                          );
}
 

#endif
