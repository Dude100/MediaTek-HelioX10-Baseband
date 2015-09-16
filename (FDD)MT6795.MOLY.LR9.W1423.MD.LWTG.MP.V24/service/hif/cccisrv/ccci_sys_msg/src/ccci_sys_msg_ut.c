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
 *   ccci_sys_msg_ut.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This function implements the CCCI_SYS_MSG UT functions for atest_sys.
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
 * [MOLY] [CCCI_UT] CCCI SYS MSG UT 1st check-in
 * [CCCI SYS MSG] Add CCCI SYS MSG UT code
 *
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "ccci_if.h"
#include "ccci_sys_msg.h"
//#include "ccci_common.h"


#ifdef ATEST_SYS_CCCI_SYS_MSG
#include "sys_test.h"
//#define __CCCI_SYS_MSG_UT__
#endif

#ifdef __CCCI_SYS_MSG_UT__

#if defined(__MTK_TARGET__)
#define _ccci_ut_printf(...) ccci_dhl_print(CCCI_ERR, CCCI_MOD_UT, __VA_ARGS__)
#else
#define _ccci_ut_printf printf
#endif

#define ccci_ut_printf(_fmts, ...) \
        _ccci_ut_printf("%s(): " _fmts, __FUNCTION__, ##__VA_ARGS__)

// init sysmsg channel
kal_bool ccci_sys_msg_init_channel()
{
	kal_int32 ret;

    ret = ccci_init(CCCI_SYSTEM_CHANNEL_ACK, ccci_system_channel_runtime_callback);
	if(ret != CCCI_SUCCESS)
		return KAL_FALSE;
	ret = ccci_init(CCCI_SYSTEM_CHANNEL, ccci_sys_msg_dlcb_dummy);
	if(ret != CCCI_SUCCESS)
		return KAL_FALSE;

	return KAL_TRUE;
}


// deinit sysmsg channel
kal_bool ccci_sys_msg_deinit_channel()
{
	kal_int32 ret;

    ret = ccci_deinit(CCCI_SYSTEM_CHANNEL_ACK);
	if(ret != CCCI_SUCCESS)
		return KAL_FALSE;
	ret = ccci_deinit(CCCI_SYSTEM_CHANNEL);
	if(ret != CCCI_SUCCESS)
		return KAL_FALSE;

	return KAL_TRUE;
}

// sysmsg dummy cb function
kal_bool ccci_sys_msg_user_dummy_cb(kal_uint32 param)
{
	ccci_ut_printf("Test ccci sys msg loop back OK.\r\n");
	return KAL_TRUE;
}

//3 1.1 ccci sys msg init test
kal_bool ccci_sys_msg_ut_init_test(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    kal_int32 ret;
	// deinit sysmsg channel
    ret = ccci_sys_msg_deinit_channel();
    if(ret == KAL_FALSE)
		return KAL_FALSE;
	
	// init sysmsg channel
    ret = ccci_sys_msg_init_channel();
	if(ret == KAL_FALSE)
		return KAL_FALSE;
	
	//1.1.1 over msg id < start or > end, expect returning KAL_FALSE
    ret = ccci_register_sysmsgsvc_callback(CCMSG_ID_SYSMSGSVC_START-1, ccci_sys_msg_user_dummy_cb);
    if(ret == KAL_TRUE)
		return KAL_FALSE;
    
    ret = ccci_register_sysmsgsvc_callback(CCMSG_ID_SYSMSGSVC_END, ccci_sys_msg_user_dummy_cb);
	if(ret == KAL_TRUE)
		return KAL_FALSE;
	
    //1.1.2 callback function is null, expect returning KAL_FALSE
	ret = ccci_register_sysmsgsvc_callback(CCMSG_ID_SYSMSGSVC_START, NULL);
    if(ret == KAL_TRUE)
		return KAL_FALSE;
    
	ccci_ut_printf("Test ccci sys msg init OK.\r\n");
    return KAL_TRUE; 
}

//3 1.2 ccci sys msg lb test
kal_bool ccci_sys_msg_ut_lb_test(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    kal_int32 ret;
    CCCI_BUFF_T *ccci_buff;
    kal_char data_buff[16];

	//2 1 deinit sysmsg channel
    ret = ccci_sys_msg_deinit_channel();
    if(ret == KAL_FALSE)
		return KAL_FALSE;
	
	//3 2 init sysmsg channel
    ret = ccci_sys_msg_init_channel();
	if(ret == KAL_FALSE)
		return KAL_FALSE;
	
    //4 3 register ut msg to user dummy cb
	ret = ccci_register_sysmsgsvc_callback(CCMSG_ID_SYSMSGSVC_UT_ONLY, ccci_sys_msg_user_dummy_cb);
	if(ret == KAL_FALSE)
		return KAL_FALSE;
	
    //4 4 write a test msg and will receive rx cb
    
    memset(data_buff, 0, sizeof(data_buff));
    ccci_buff = (CCCI_BUFF_T*)data_buff;
    CCCI_INIT_MAILBOX(ccci_buff, CCMSG_ID_SYSMSGSVC_UT_ONLY);
    CCCI_SET_CH_NO(ccci_buff, CCCI_SYSTEM_CHANNEL_ACK);

    CCCI_SET_RESERVED(ccci_buff, 0);

    ccci_ulbuff_cb(CCCI_SYSTEM_CHANNEL_ACK, ccci_buff);
    
	//4 5 tx cb does not implement

    return KAL_TRUE; 
}

#ifdef ATEST_SYS_CCCI_SYS_MSG
extern kal_bool st_reg_test(kal_char *p_mod_name, ST_TCASE_T *p_tcase, kal_uint32 tcase_num);

ST_TCASE_T st_tcase_ccci_sys_msg_g[] = {
    {"1.1 ccci sys msg init test",           ccci_sys_msg_ut_init_test,   NULL}, 
	{"1.2 ccci sys msg loopback test",		 ccci_sys_msg_ut_lb_test, 	  NULL}, 
};
kal_uint32 st_tcase_count_ccci_sys_msg_g = sizeof(st_tcase_ccci_sys_msg_g) / sizeof(ST_TCASE_T);

kal_bool ccci_sys_msg_ut_st_create()
{
    return st_reg_test("CCCI_SYS_MSG", st_tcase_ccci_sys_msg_g, st_tcase_count_ccci_sys_msg_g);
}


#endif


#endif // end __CCCI_SYS_MSG_UT__

