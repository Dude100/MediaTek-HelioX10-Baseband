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
 *   ccci_ipc_ut.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This function implements the CCCI_IPC UT functions for atest_sys.
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
 * [CCCI IPC] Support Clibtime feature
 *
 * 01 23 2013 ap.wang
 * removed!
 * [CCCI IPC UT] Modiy ccci_ipc_ut, decouple from ccci and sdio
 *
 * 01 11 2013 ap.wang
 * removed!
 * [CCCI_IPC UT] Modify CCCI_IPC_UT error
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/


#include "ccci_ipc_common.h"
#include "ccci_ipc_data.h"

#ifdef ATEST_SYS_CCCI_IPC
#include "sys_test.h"
#endif

#if _MSC_VER
#define snprintf _snprintf
#endif

#ifdef __CCCI_IPC_UT__

extern CCCI_IPC_ILM_T ccci_ipc_ilm_arr[];

void ccci_ipc_ut_dummy_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior){
    
    ASSERT(0);
    return;
}

/*************************************************************************
* FUNCTION
*  ccci_ipc_deinit
*
* DESCRIPTION
*  This function is to de-initialize ipc message passing service
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
extern CCCI_IPC_T ccci_ipc_ch;
void ccci_ipc_ut_deinit(void)
{
    //Send message does not need callback
    ccci_deinit(ccci_ipc_ch.send_channel);
    //send mesage ack need to implement callback
    ccci_deinit(ccci_ipc_ch.send_ack_channel );
    //Receive mesage need to implement callback
    ccci_deinit(ccci_ipc_ch.receive_channel);
    //Receive mesage ack does not need to implement callback
    ccci_deinit(ccci_ipc_ch.receive_ack_channel);
}

kal_bool ccci_ipc_ut_init_test(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 total_err_str_size = p_ret_err_str_sz;
    kal_int32  ret = CCCI_SUCCESS;

    //4 <0>deinit ipc channels for init test
    ccci_ipc_ut_deinit();
    ccci_ipc_init();

    //4 <1>Channel initial test => except return CCCI_IN_USE
    ret = ccci_init_gpdior(ccci_ipc_ch.send_channel, ccci_ipc_ut_dummy_cb);
    if (ret != CCCI_IN_USE){
         snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
                  "[CCCI_IPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_ipc_ch.send_channel);  
         return KAL_FALSE;
    }
//	    ret = ccci_init_gpdior(ccci_ipc_ch.send_ack_channel, ccci_ipc_ut_dummy_cb);
//	    if (ret != CCCI_IN_USE){
//	         snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
//	                  "[CCCI_IPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_ipc_ch.send_ack_channel);  
//	         return KAL_FALSE;
//	    }
    ret = ccci_init_gpdior(ccci_ipc_ch.receive_channel, ccci_ipc_ut_dummy_cb);
    if (ret != CCCI_IN_USE){
         snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
                  "[CCCI_IPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_ipc_ch.receive_channel);
         return KAL_FALSE;
    }
//	    ret = ccci_init_gpdior(ccci_ipc_ch.receive_ack_channel, ccci_ipc_ut_dummy_cb);
//	    if (ret != CCCI_IN_USE){
//	         snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
//	                  "[CCCI_IPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_ipc_ch.receive_ack_channel);
//	         return KAL_FALSE;
//	    }

    return KAL_TRUE; 
}


/**
 * Fake L4c send ilm use CCCI_IPC function
 *
 * Alloc ilm point from CCCI_IPC and fill in data same as the origingal function
 * Used by ccci_ipc_ut_send_msg to check the function work correctly.
 *
 * @return KAL_TRUE - pass, KAL_FALSE - fault
 */
kal_bool ccci_ipc_ut_fake_l4c_send_ilm_ipc(msg_type msg_name, void *param_ptr){
    ipc_ilm_t *ilm_ptr = NULL;

    /* allocate and fill cross message structure */
    ilm_ptr = ipc_msgsvc_allocate_ilm(MOD_L4C);
    ilm_ptr->src_mod_id = MOD_L4C;
    ilm_ptr->dest_mod_id = APMOD_AGPS;
    ilm_ptr->msg_id = (kal_uint32)msg_name;
    ilm_ptr->peer_buff_ptr = NULL; /* no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;
//	    ilm_ptr->sap_id = MMI_L4C_SAP;
    return ipc_msgsvc_send_ext_queue(ilm_ptr);
}

/**
 * ccci_ipc_ut_ccci_write_gpd to simulate a ccci_write_gpd function
 *
 * ccci_ipc_ut_ccci_write_gpd check the ior as ccci_write_gpd and 
 * do tx done call back.
 *
 * @return KAL_TRUE 
 */

static kal_int32 ccci_ipc_ut_ccci_write_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo){

    /* check parameters */
    if (channel >= CCCI_MAX_CHANNEL){
        return CCCI_INVALID_PARAM;
    }
    if (p_ccci_DL_ior->first_gpd == NULL){
        /*"partial" check: although there might be other ior, don't want to spend too much time on traversing*/
        return CCCI_INVALID_PARAM;
    }
    if (p_ccci_DL_ior->last_gpd == NULL){
        /*"partial" check: although there might be other ior, don't want to spend too much time on traversing*/
        return CCCI_INVALID_PARAM;
    }

    QBM_DES_SET_NEXT(p_ccci_DL_ior->last_gpd, NULL);
    p_ccci_DL_ior->last_gpd = NULL;
    ccci_ipc_send_msg_cb(channel, p_ccci_DL_ior);
   
    return CCCI_SUCCESS;
}

kal_bool ccci_ipc_ut_send_msg(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 total_err_str_size = p_ret_err_str_sz;
    kal_int32  ret = KAL_TRUE;
    ipc_ilm_t  ipc_ilm = {0};
    ipc_ilm_t  *ilm_ptr = NULL;

    ccci_ipc_ch.ccci_write_gpd = ccci_ipc_ut_ccci_write_gpd;
    //4  <1> sned ilm form ccci_ipc_ut_fake_l4c_send_ilm_ipc, expect return kal_true
    
    ret = ccci_ipc_ut_fake_l4c_send_ilm_ipc(MSG_ID_IPC_L4C_INVALID, NULL);
    if (ret == KAL_FALSE){
        snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
                  "[CCCI_IPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_ipc_ch.receive_ack_channel);
        goto error;
    }

    //4 <2> send ilm with self alloc ipc_ilm struct, expect return kal_false
    ipc_ilm.src_mod_id = MOD_L4C;
    ipc_ilm.dest_mod_id = APMOD_AGPS;
    ret = ipc_msgsvc_send_ext_queue(&ipc_ilm);
    if (ret != KAL_FALSE){
        snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
                  "[CCCI_IPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_ipc_ch.receive_ack_channel);
        goto error;
    }

    //4 <3>send ilm with error src_mod_id = alloc module id
    ilm_ptr = ipc_msgsvc_allocate_ilm(MOD_L4C);
    ilm_ptr->src_mod_id = MOD_CCCIIPC;
    ret = ipc_msgsvc_send_ext_queue(ilm_ptr);
    if (ret != KAL_FALSE){
        snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
                  "[CCCI_IPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_ipc_ch.receive_ack_channel);
        goto error;
    }
	ccci_ipc_ilm_arr[0].used = 0;

    //4 <3>send ilm with error src_mod_id
    //ilm_ptr = ipc_msgsvc_allocate_ilm(MOD_L4C);
    ilm_ptr->src_mod_id = MOD_CCCIRPC;
    ret = ipc_msgsvc_send_ext_queue(ilm_ptr);
    if (ret != KAL_FALSE){
        snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
                  "[CCCI_IPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_ipc_ch.receive_ack_channel);
        goto error;
    }
    
    ccci_ipc_ch.ccci_write_gpd = ccci_write_gpd;
    return KAL_TRUE;  
error:
    ccci_ipc_ch.ccci_write_gpd = ccci_write_gpd;
    return KAL_FALSE;
}


extern IPC_MSGSVC_TASKMAP_T ccci_ipc_maptbl[];
kal_bool ccci_ipc_ut_receive_msg(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 total_err_str_size = p_ret_err_str_sz;
    ccci_io_request_t ior = {0};
    CCCI_BUFF_T *p_ccci_buff = 0;
    ipc_ilm_t  *ilm_ptr = NULL;
    
#ifdef __SDIOC_PULL_Q_ENH_DL__
    ior.num_gpd = 
#endif 
    qbmt_alloc_q_no_tail( 
                        CCCI_IPC_GPD_TYPE,            /* type */
                        1,                            /* buff_num */
                        (void **)(&ior.first_gpd),    /* pp_head */
                        (void **)(&ior.last_gpd));    /* pp_tail */
    
	//initialize ccci_buffer content
	p_ccci_buff = CCCIDEV_GET_QBM_DATAPTR(ior.first_gpd);
	p_ccci_buff->data[1] = sizeof(CCCI_BUFF_T) + sizeof(ipc_ilm_t) + sizeof(local_para_struct);
	p_ccci_buff->channel = (kal_uint32)ccci_ipc_ch.receive_channel;
	p_ccci_buff->reserved = (kal_uint32)ccci_ipc_maptbl[0].extq_id;

    //set ilm
    ilm_ptr = p_ccci_buff + sizeof(CCCI_BUFF_T);
    ilm_ptr->src_mod_id = ccci_ipc_maptbl[1].extq_id; 
    ilm_ptr->local_para_ptr = ilm_ptr + sizeof(ipc_ilm_t);
    ilm_ptr->local_para_ptr->msg_len = sizeof(local_para_struct);
    ilm_ptr->local_para_ptr->ref_count = 1;

    ccci_ipc_receive_msg_cb(ccci_ipc_ch.receive_channel, &ior);

    return KAL_TRUE; 
}

typedef struct ccci_ipc_test_struct
{
    kal_uint8 ref_count;
    kal_uint8 lp_reserved;
    kal_uint16 msg_len;
    kal_uint8 test[32];
}ccci_ipc_test_struct_t;
char comp_string[] = "abcdefghijklmnopqrstuvwxyz";
void ccci_ipc_ut_cb_funp(ilm_struct *ilm)
{
    ccci_ipc_test_struct_t *test_t;
    // compare msgid
    if(ilm->msg_id != MSG_ID_IPC_CCCIIPC_INVALID)
        ASSERT(0);
    test_t = (ccci_ipc_test_struct_t *) ilm->local_para_ptr;
    // compare local param data
    if(kal_mem_cmp((void *) test_t->test ,(void *) comp_string,sizeof(comp_string)) !=0)
        ASSERT(0);
}

kal_bool ccci_ipc_ut_misc(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 total_err_str_size = p_ret_err_str_sz;
    ipc_ilm_t  *ilm_ptr = NULL;
    ilm_struct test_ilm = {0};
    ipc_ilm_t  test_ilm_cb = {0};
    kal_bool   rtn = KAL_FALSE;
    ccci_ipc_test_struct_t *test_t;

    //4 <1> Alloc ILM function test 
    ilm_ptr = ipc_msgsvc_allocate_ilm(MOD_L4C);
    if (&ccci_ipc_ilm_arr[0].ipc_ilm == ilm_ptr){
        if (ccci_ipc_ilm_arr[0].used != 1){
            snprintf(p_ret_err_str, total_err_str_size, "%s%s:ccci_ipc_ilm_arr[0].used = %d \n", 
                  "[CCCI_IPC_UT] ccci_ipc_ut_misc ", "ipc_msgsvc_allocate_ilm(MOD_L4C) error",
                  ccci_ipc_ilm_arr[0].used);
            return KAL_FALSE;
        }
        ccci_ipc_ilm_arr[0].used = 0;
    }
    
    ilm_ptr = ipc_msgsvc_allocate_ilm(MOD_CCCIRPC);
    if ( ilm_ptr != NULL ){
        snprintf(p_ret_err_str, total_err_str_size, "%s%s:ilm_ptr = %x \n", 
                  "[CCCI_IPC_UT] ccci_ipc_ut_misc ", "ipc_msgsvc_allocate_ilm(MOD_CCCIIPC) returns error ",
                  ilm_ptr);
        return KAL_FALSE;
    }
    ccci_ipc_ilm_arr[0].used = 0;
    
    //4 <2> CCCI_IPC main_init and ilm hanle test
    ccci_ipc_task_main_init();
    ccci_ipc_main(&test_ilm);
    
    //4 <3> Unit Test register cb funp
    // Test registration
    rtn = ccci_register_ipc_cb_funp(MSG_ID_IPC_CCCIIPC_INVALID, ccci_ipc_ut_cb_funp);
    if(rtn == KAL_FALSE) return KAL_FALSE; // should return kal_true
    // Test re-registration, should be failed
    rtn = ccci_register_ipc_cb_funp(MSG_ID_IPC_CCCIIPC_INVALID, ccci_ipc_ut_cb_funp);
    if(rtn == KAL_TRUE) return KAL_FALSE; // should return kal_false
    rtn = ccci_register_ipc_cb_funp(MSG_ID_IPC_CCCIIPC_INVALID, NULL);
    if(rtn == KAL_TRUE) return KAL_FALSE; // NULL cb funp should return kal_false
  
    //4 <4> Unit test ccci_ipc_process_ilm
    // the msg had registered cb funp
    test_ilm_cb.msg_id = MSG_ID_IPC_CCCIIPC_INVALID; 
    test_ilm_cb.local_para_ptr = (local_para_struct *) construct_local_para(sizeof(ccci_ipc_test_struct_t),TD_RESET);
    test_t = (ccci_ipc_test_struct_t *) test_ilm_cb.local_para_ptr;
    kal_mem_cpy(test_t->test, (void *)comp_string, sizeof(comp_string));
    rtn = ccci_ipc_process_cb_funp(&test_ilm_cb);
    if(rtn == KAL_FALSE) return KAL_FALSE; // should return kal_true
    // the msg id had not registered cb funp, should be failed
    test_ilm_cb.msg_id = MSG_ID_IPC_CCCIIPC_END;
    rtn = ccci_ipc_process_cb_funp(&test_ilm_cb);
    if(rtn == KAL_TRUE) return KAL_FALSE;// should return kal_false

    
    return KAL_TRUE; 
}



#ifdef ATEST_SYS_CCCI_IPC
extern kal_bool st_reg_test(kal_char *p_mod_name, ST_TCASE_T *p_tcase, kal_uint32 tcase_num);

ST_TCASE_T st_tcase_ccci_ipc_g[] = {
    {"1.1 ccci_ipc_ut_init_test",    ccci_ipc_ut_init_test,       NULL}, 
    {"1.2 ccci_ipc_ut_send_msg",     ccci_ipc_ut_send_msg,        NULL},
    {"1.3 ccci_ipc_ut_receive_msg",  ccci_ipc_ut_receive_msg,     NULL},
    {"1.4 ccci_ipc_ut_misc",         ccci_ipc_ut_misc,            NULL}
};
kal_uint32 st_tcase_count_ccci_ipc_g = sizeof(st_tcase_ccci_ipc_g) / sizeof(ST_TCASE_T);

kal_bool ccci_ipc_ut_st_create()
{
    return st_reg_test("CCCI_IPC", st_tcase_ccci_ipc_g, st_tcase_count_ccci_ipc_g);
}
#endif

#endif //  __CCCI_IPC_UT__



