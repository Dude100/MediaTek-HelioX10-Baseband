
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
 *   ccci_ipc_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implements the CCCI_IPC IT functions for CCCI IT framework.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI RPC] Add CCCI RPC general query function.
 *
 * 06 27 2013 ap.wang
 * removed!
 * [CCCI_RPC] Modify for sceurity RPC service
 *
 * 05 09 2013 ap.wang
 * removed!
 * [CCCI RPC] CCCI RPC IT modify and rx callback rule modify
 *
 * removed!
 * removed!
 * fix compile warning and build error
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "ccci_rpc_common.h"
#include "ccci_rpc_data.h"
#include "kal_debug.h"

#ifdef __CCCI_IT_CTRL__

#include "dhl_trace.h"
#define DBG(_c,_f,...) dhl_print(_c, DHL_USER_FLAG_NONE, MOD_CCCI_IT_CTRL, "[CCCI_RPC_IT] %s %d: "_f, __FUNCTION__, __LINE__  , ##__VA_ARGS__);


/*******************************************************************************
 * Define macro
 *******************************************************************************/
#if _MSC_VER
#define snprintf _snprintf
#endif

/*******************************************************************************
 * Define functions.
 *******************************************************************************/
#include "md_mmi_sap.h"

#define GPIONameLength_ut_val 20
#define GPIONumInputPar 2
#define GPIONumOutputPar 1
#define GPIOPin_it_back_val 10
#define IPC_RPC_GPIO_GETPIN_OP_ut_val 1234
#define GPIOName_string_contend "GPIO_AST_AFC_Switch"
void *GPIOName_ut_val = "GPIO_AST_AFC_Switch";


kal_bool ccci_rpc_ut_fake_gpio_getpin_send_rpc(void){
	kal_uint32 GPIONameLength = GPIONameLength_ut_val;
	kal_uint32 GPIOPin;
	kal_int32 ret;
	kal_uint8 *GPIOName = (kal_uint8 *)GPIOName_ut_val;
    
    ret =  IPC_RPC_Wrapper(IPC_RPC_GPIO_GETPIN_OP_ut_val,		GPIONameLength,		(void *)GPIOName,
                           sizeof(kal_uint32), (void *)&GPIONameLength,	IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32),  (kal_uint32*)(&GPIOPin), IPC_RPC_EOF_TERM_PATTERN);

    if(ret<0)
    {
        DBG(TRACE_ERROR, "Return Value: %d",ret);
        return KAL_FALSE;
    }
    if(GPIOPin == GPIOPin_it_back_val  ){
		return KAL_TRUE;
	}
	else{
		return KAL_FALSE;
	}	
}


#define md_gpd_idx_ut_val       1
#define num_para_from_md_ut_val 2
#define num_para_from_ap_ut_val 2
#define EEMCS_OP_IT_VAL         0x4321

kal_bool eemcs_rpc_it_send_rpc(void){
	kal_int32 ret;
	kal_uint32 LV1_Length = 4;
	kal_uint32 LV1_Value = 0xbeef;
	kal_uint32 LV2_Length = 4;
	kal_uint32 LV2_Value = 0xbeef;
	kal_uint32 it_ret_val = -100;


    ret =  IPC_RPC_Wrapper(EEMCS_OP_IT_VAL,		LV1_Length,		(kal_uint32 *)(&LV1_Value),
                           LV2_Length, (kal_uint32 *)(&LV2_Value),	IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32),  (kal_uint32*)(&it_ret_val),			IPC_RPC_EOF_TERM_PATTERN);

    if(ret<0)
    {
        DBG(TRACE_ERROR, "Return Value: %d",ret);
        return KAL_FALSE;
    }
    if(it_ret_val == 0xa5a5  ){
		return KAL_TRUE;
	}
	else{
		return KAL_FALSE;
	}   

}



kal_bool eemcs_rpc_it_GPIO(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
	kal_int32 ret;
	kal_uint32 LV1_Length = strlen("GPIO_MD_TEST")+1;
	kal_uint8  LV1_Value[] = "GPIO_MD_TEST";
	kal_uint32 LV2_Length = 4;
	kal_uint32 LV2_Value = strlen("GPIO_MD_TEST")+1;
	kal_uint32 it_ret_val = -100;


    ret =  IPC_RPC_Wrapper(IPC_RPC_GPIO_GETPIN_OP,		LV1_Length,		(void *)(&LV1_Value),
                           LV2_Length, (kal_uint32 *)(&LV2_Value),	IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32),  (kal_uint32*)(&it_ret_val),	IPC_RPC_EOF_TERM_PATTERN);
       
    if(ret<0)
    {
        DBG(TRACE_ERROR, "Return Value: %d",ret);
        return KAL_FALSE;
    }
    if(it_ret_val == 800){
		return KAL_TRUE;
	}
	else{
		return KAL_FALSE;
	}   

}


kal_bool eemcs_rpc_it_EMI_CLK_TYPE(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
	kal_int32 ret;
	kal_uint32 it_ret_val1 = 0;
    kal_uint32 it_ret_val2 = 0;
    
    ret =  IPC_RPC_Wrapper(IPC_RPC_QUERY_EMI_OP,		
                           IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32),  (kal_uint32*)(&it_ret_val1),	
                           sizeof(kal_uint32),  (kal_uint32*)(&it_ret_val2), 
                           IPC_RPC_EOF_TERM_PATTERN);
       
    if(ret<0)
    {
        DBG(TRACE_ERROR, "Return Value: %d",ret);
        return KAL_FALSE;
    }else{
        DBG(TRACE_ERROR, "Return Value: %d Result: %d  %d", ret, it_ret_val1, it_ret_val2);
        return KAL_TRUE;
    }
}


kal_bool eemcs_rpc_it_EINT_ATTR(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
	kal_int32 ret;
	kal_char   LV1_Value[]= "MD1_SIM1_HOT_PLUG_EINT";
    kal_uint32 LV1_Length = strlen(LV1_Value)+1;
    kal_uint32 LV2_Length = 4;
	kal_uint32 LV2_Value  = strlen(LV1_Value)+1;
    kal_uint32 LV3_Length = 4;
	kal_uint32 LV3_Value  = 0;
    kal_uint8  it_ret_val2[2048] = {0};
    
    ret =  IPC_RPC_Wrapper(IPC_RPC_EINT_GETATTRIBUTE_OP,		
                           LV1_Length, (void *)(&LV1_Value),
                           LV2_Length, (void *)(&LV2_Value),
                           LV3_Length, (void *)(&LV3_Value),
                           IPC_RPC_INPUT_TERM_PATTERN,
                           2048, (void*)(&it_ret_val2), 
                           IPC_RPC_EOF_TERM_PATTERN);
       
    if(ret<0)
    {
        DBG(TRACE_ERROR, "Return Value: %d",ret);
        return KAL_FALSE;
    }else{
        DBG(TRACE_ERROR, "Return Value: %d Result: %d", ret, it_ret_val2[0]);
        return KAL_TRUE;
    }
}

typedef struct CCCI_CLKBUF_INPUT_T{
kal_uint16 CLKBuf_Count;
}CCCI_CLKBUF_INPUT;

#define CLKBUF_MAX_COUNT 4
typedef struct CCCI_CLKBUF_RESULT_T{
kal_uint16 CLKBuf_Count;
kal_uint8 CLKBuf_Status[CLKBUF_MAX_COUNT];
} CCCI_CLKBUF_RESULT;
CCCI_CLKBUF_INPUT ccci_clkbuf_input;
CCCI_CLKBUF_RESULT ccci_clkbuf_output; // for ICE

kal_bool eemcs_rpc_it_RF_CLK_BUFFER_CONTROL(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
	kal_int32 ret;
	ccci_clkbuf_input.CLKBuf_Count =4;
    ret =  IPC_RPC_General_Query(IPC_RPC_RF_CLK_BUFFER_OP,		
                           (void *) &ccci_clkbuf_input, sizeof(CCCI_CLKBUF_INPUT),
                           (void *) &ccci_clkbuf_output, sizeof(CCCI_CLKBUF_RESULT));
       
    if(ret<0)
    {
        DBG(TRACE_ERROR, "Return Value: %d",ret);
        return KAL_FALSE;
    }else{
        DBG(TRACE_ERROR, "Return Value: %d Result: %d", ret, ccci_clkbuf_output.CLKBuf_Count);
        return KAL_TRUE;
    }
}

//use char device do it loop back
kal_bool ccci_rpc_it_rpc(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

    if(ccci_rpc_ut_fake_gpio_getpin_send_rpc())
		return KAL_TRUE;
	else
	    return KAL_FALSE;
}

//use eemcs rpc do it 
kal_bool eemcs_rpc_it_rpc(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

    if(eemcs_rpc_it_send_rpc())
		return KAL_TRUE;
	else
	    return KAL_FALSE;
}

#ifdef __CCCI_IT_CTRL__
#include "ccci_it_ctrl_if.h"
//AT+CCCI_RPC=1,2,3...
IT_MODE_T ccci_rpc_it_mode_table[] = {    
    {"eemcs_rpc_it_rpc",    eemcs_rpc_it_rpc,       NULL},
//	    {"ccci_rpc_it_rpc" ,    ccci_rpc_it_rpc,        NULL},
    {"eemcs_rpc_it_GPIO",            eemcs_rpc_it_GPIO,             NULL},
    {"eemcs_rpc_it_EMI_CLK_TYPE",    eemcs_rpc_it_EMI_CLK_TYPE,     NULL},
    {"eemcs_rpc_it_EINT_ATTR",       eemcs_rpc_it_EINT_ATTR,        NULL},
	{"eemcs_rpc_it_RF_CLK_BUFFER_CONTROL",       eemcs_rpc_it_RF_CLK_BUFFER_CONTROL,        NULL},
};

kal_bool ccci_rpc_it_create(){
	
return ccci_it_mode_control_table_reg("CCCI_RPC", 
                     ccci_rpc_it_mode_table, 
                     sizeof(ccci_rpc_it_mode_table) / sizeof(IT_MODE_T) 
                    );
}
 
#endif
#endif
