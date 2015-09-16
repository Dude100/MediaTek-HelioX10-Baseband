

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
 *   ccci_rpc_ut.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This function implements the CCCI_RPC UT functions for atest_sys.
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
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI RPC] Add CCCI RPC general query function.
 *
 * 05 14 2013 ap.wang
 * removed!
 * [CCCI RPC] Add trace log
 *
 * 05 14 2013 ap.wang
 * removed!
 * [CCCI RPC] Add trace log
 *
 * removed!
 * removed!
 * fix compile warning and build error
 *
 * 01 11 2013 ap.wang
 * removed!
 * [CCCI_RPC UT] Modify CCCI_RPC_UT error
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/


#include "ccci_rpc_common.h"
#include "ccci_rpc_data.h"
#include "ccci_rpc_if.h"

#ifdef ATEST_SYS_CCCI_RPC
#include "sys_test.h"
#endif

#if _MSC_VER
#define snprintf _snprintf
#endif

#ifdef __CCCI_RPC_UT__

void ccci_rpc_ut_dummy_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior){
    
    ASSERT(0);
    return;
}

/*************************************************************************
* FUNCTION
*  ccci_rpc_deinit
*
* DESCRIPTION
*  This function is to de-initialize rpc message passing service
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
extern CCCI_RPC_T ccci_rpc_ch;
extern RPC_GPDS_POOL_T rpc_gpd_pool[CCCI_RPC_GPD_NUMBER];

void ccci_rpc_ut_deinit(void)
{
    //Send message does not need callback
    ccci_deinit(ccci_rpc_ch.send_channel);
    //Receive mesage need to implement callback
    ccci_deinit(ccci_rpc_ch.receive_channel);
}
//=====================
//1.1 ccci_rpc_ut_init_test
//=====================
kal_bool ccci_rpc_ut_init_test(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    kal_uint32 total_err_str_size = *p_ret_err_str_sz;
    kal_uint32  ret = CCCI_SUCCESS;

    //4 <0>deinit rpc channels for init test
    ccci_rpc_ut_deinit();
    ccci_rpc_init();

    //4 <1>Channel initial test => except return CCCI_IN_USE
    ret = ccci_init_gpdior(ccci_rpc_ch.send_channel, ccci_rpc_ut_dummy_cb);
    if (ret != CCCI_IN_USE){
         snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
                  "[CCCI_RPC_UT] ccci_ut_misc test 2.1 ", "ccci_init_gpdior returns", ret, ccci_rpc_ch.send_channel);  
         return KAL_FALSE;
    }

    ret = ccci_init_gpdior(ccci_rpc_ch.receive_channel, ccci_rpc_ut_dummy_cb);
    if (ret != CCCI_IN_USE){
         snprintf(p_ret_err_str, total_err_str_size, "%s%s:%d channel %d \n", 
                  "[CCCI_RPC_UT] ccci_ut_init test 1.1 ", "ccci_init_gpdior returns", ret, ccci_rpc_ch.receive_channel);
         return KAL_FALSE;
    }

    return KAL_TRUE; 
}





//=====================
//1.2 ccci_rpc_ut_send_test
//=====================

#define GPIONameLength_ut_val 20
#define GPIONumInputPar 2
#define GPIONumOutputPar 1
#define GPIOPin_ut_val 10
#define IPC_RPC_GPIO_GETPIN_OP_ut_val 1234
#define GPIOName_string_contend "GPIO_AST_AFC_Switch"
void *GPIOName_ut_val = "GPIO_AST_AFC_Switch";

static kal_int32 check_reload_read_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo)
{
    if(channel != ccci_rpc_ch.receive_channel){
		ASSERT(0);    
	}
	if(p_ccci_DL_ior->first_gpd->data_len   != 0){
			ASSERT(0);	  
	}
    return KAL_TRUE;
}
static kal_int32 ccci_rpc_ut_gpio_getpin_ccci_write_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo)
{
	pIPC_RPC_StreamBuffer_T temp_rpc_buffer;
	kal_uint8 * ptr;
	kal_uint8 * ptr_temp;
	kal_uint8 i;
	kal_uint8 GPIOName_string_ut_val[GPIONameLength_ut_val] = {GPIOName_string_contend};
	//get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(p_ccci_DL_ior->first_gpd);
    //copy opid, number of LV, LV[]  into ccci data field
	
   	if(temp_rpc_buffer->rpc_opid != IPC_RPC_GPIO_GETPIN_OP_ut_val)
	{
	  
		ASSERT(0);
		//wrong op
	    return CCCI_INVALID_PARAM;
	}
	if(temp_rpc_buffer->num_para!= GPIONumInputPar)
	{
	    ASSERT(0);
		//wrong number of LV pairs
	}
	//- point to LV[0]
    ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);
    if (*ptr != GPIONameLength_ut_val)	
	{
		ASSERT(0);
		//wrong LV[0] L
	}
    ptr += sizeof(kal_uint32);
	ptr_temp = ptr;
	for( i = 0; i < GPIONameLength_ut_val ; i++){
		if ( *ptr_temp != GPIOName_string_ut_val[i])	
		{
			ASSERT(0);
			//wrong LV[0] V
		}
		ptr_temp++;
	}
    
	ptr += GPIONameLength_ut_val;
    if (*ptr != sizeof(kal_uint32))	
	{
		ASSERT(0);
		//wrong LV[1] L
	}	
    ptr += sizeof(kal_uint32);
    if (*ptr != GPIONameLength_ut_val)	
	{
        ASSERT(0);
		//wrong LV[1] V
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
#endif

	QBM_DES_SET_NEXT(p_ccci_DL_ior->last_gpd, NULL);
	p_ccci_DL_ior->last_gpd = NULL;
	//p_ccci_DL_ior->last_gpd = p_ccci_DL_ior->first_gpd;
	ccci_rpc_ch.ccci_write_gpd = check_reload_read_gpd;
	ccci_rpc_send_cb(channel, p_ccci_DL_ior);

	return CCCI_SUCCESS;
}

//send
//extern kal_int32 IPC_RPC_GPIO_GetPin(kal_uint8 *GPIOName, kal_uint32 GPIONameLength, kal_uint32 *GPIOPin);

kal_bool ccci_rpc_ut_fake_gpio_getpin_send_rpc(void){
	kal_uint32 GPIONameLength = GPIONameLength_ut_val;
	
	kal_int32 ret;
    //kal_uint8 temp = GPIOName_ut_val;
	//GPIOName = &temp;
	kal_uint8 *GPIOName = GPIOName_ut_val;
	
	kal_uint32 GPIOPin; //unsigned char

    ret =  IPC_RPC_Wrapper(IPC_RPC_GPIO_GETPIN_OP_ut_val,		GPIONameLength,		(void *)GPIOName,
                           sizeof(kal_uint32), (void *)&GPIONameLength,	IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32),  (kal_uint32*)(&GPIOPin),			IPC_RPC_EOF_TERM_PATTERN);


    return ret;
	
}

kal_bool ccci_rpc_ut_send(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    kal_int32 ret;

	//4 (1) gpio getpin simulation
	
    ccci_rpc_ch.ccci_write_gpd = ccci_rpc_ut_gpio_getpin_ccci_write_gpd;	
	ret =  ccci_rpc_ut_fake_gpio_getpin_send_rpc();
	if(ret != CCCI_SUCCESS) goto error;

	ccci_rpc_ch.ccci_write_gpd = ccci_write_gpd;
	return KAL_TRUE;  
error:
	ccci_rpc_ch.ccci_write_gpd = ccci_write_gpd;
	return KAL_FALSE;
}


//=====================
//1.3 ccci_rpc_ut_read_test
//=====================

#define gpio_getpin_used_gpd_idx_ut_val 1

static kal_int32 ccci_rpc_ut_fake_gpio_getpin_ccci_read_rpc(void)
{
	ccci_io_request_t ior= {0};
	pIPC_RPC_StreamBuffer_T temp_rpc_buffer;
    kal_uint8 * ptr;
    IPC_RPC_LV_T LV[10];
    kal_uint32 ret=0,  num;
	kal_uint32 init_GPIOPin = 7;
	kal_uint32 * GPIOPin; 
    num = GPIONumOutputPar;
    GPIOPin = &init_GPIOPin;
	//fill ior==============
	//CCCI_RPC_ENTER_CRITICAL_SECTION
    if (KAL_TRUE == kal_query_systemInit()){ // polling mode
    //in init - use pd
	    ior.first_gpd = ccci_rpc_ch.p_polling_gpd;
	    ior.last_gpd  = ccci_rpc_ch.p_polling_gpd;
    }
    else{ 
	//after init - use gpd
		if (rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_occupied != 0){
			ASSERT(0);
		}
		rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_occupied = 1;
		ior.first_gpd = (qbm_gpd *)rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_ptr;
		ior.last_gpd  = (qbm_gpd *)rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_ptr;
        rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_ptr = NULL;
    }
    //already get gpd
	/* Exit critical section */ 
	//CCCI_RPC_EXIT_CRITICAL_SECTION
	//get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(ior.first_gpd);
	//asign used gpd index
	temp_rpc_buffer->ccci_header.reserved = gpio_getpin_used_gpd_idx_ut_val;
    temp_rpc_buffer->ccci_header.channel = ccci_rpc_ch.receive_channel;
	temp_rpc_buffer->ccci_header.data[1] = 4*sizeof(kal_uint32);
	//copy opid, number of LV, LV[]  into ccci data field
	temp_rpc_buffer->rpc_opid = (IPC_RPC_API_RESP_ID |IPC_RPC_GPIO_GETPIN_OP_ut_val);
	temp_rpc_buffer->num_para = GPIONumOutputPar;
	
	//- point to LV[0]
	ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);
    //asign LV[0]
	*ptr = sizeof(kal_uint32);
	ptr += sizeof(kal_uint32);
	//*ptr = (void *)GPIOPin_ut_val;
    *ptr = (kal_uint32)GPIOPin_ut_val;
  
    //recieve call back function
    ccci_rpc_receive_cb(ccci_rpc_ch.receive_channel , &ior);

    /* fill the returen code */
    LV[0].len = sizeof(kal_int32);
    LV[0].val = GPIOPin; 

    /* Get the return information */
    ret = IPC_RPC_CCCI_Read(gpio_getpin_used_gpd_idx_ut_val, IPC_RPC_GPIO_GETPIN_OP_ut_val, LV, &num);


	if(*GPIOPin != init_GPIOPin)
	{
		ASSERT(0);
	    ret = CCCI_FAIL;
	}

    if (ret != CCCI_SUCCESS)
    {
        return ret;
    }
    else
    {
        return CCCI_SUCCESS;
    }

}

kal_bool ccci_rpc_ut_read(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
	kal_int32 ret = 0;
	//4 (1) gpio getpin simulation
	ret = ccci_rpc_ut_fake_gpio_getpin_ccci_read_rpc();
	if (ret == CCCI_SUCCESS)
	{
	    return KAL_TRUE;
	}
	else
	{
	    return KAL_FALSE;
	}
     
}


//=====================
//1.4 ccci_rpc_ut_whole_data_path
//=====================
#define GPIONameLength_ut_val 20
#define GPIONumInputPar 2
#define GPIONumOutputPar 1
#define GPIOPin_ut_val 10
#define IPC_RPC_GPIO_GETPIN_OP_ut_val 1234
#define GPIOName_string_contend "GPIO_AST_AFC_Switch"
//void *GPIOName_ut_val = "GPIO_AST_AFC_Switch";

static kal_int32 ccci_rpc_ut_gpio_getpin_whole_path_ccci_write_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo)
{
	pIPC_RPC_StreamBuffer_T temp_rpc_buffer;
	kal_uint8 * ptr;
	kal_uint8 * ptr_temp;
	kal_uint8 i;
	kal_uint8 GPIOName_string_ut_val[GPIONameLength_ut_val] = {GPIOName_string_contend};
    //for recieving
	ccci_io_request_t ior= {0};

    kal_uint32 ret=0, num;
	kal_uint32 init_GPIOPin = 7;
	kal_uint32 * GPIOPin; 
    num = GPIONumOutputPar;
    GPIOPin = &init_GPIOPin;

	//get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(p_ccci_DL_ior->first_gpd);
    //copy opid, number of LV, LV[]  into ccci data field

	
   	if(temp_rpc_buffer->rpc_opid != IPC_RPC_GPIO_GETPIN_OP_ut_val)
	{
	  
		ASSERT(0);
		//wrong op
	    return CCCI_INVALID_PARAM;
	}
	if(temp_rpc_buffer->num_para!= GPIONumInputPar)
	{
	    ASSERT(0);
		//wrong number of LV pairs
	}
	//- point to LV[0]
    ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);
    if (*ptr != GPIONameLength_ut_val)	
	{
		ASSERT(0);
		//wrong LV[0] L
	}
    ptr += sizeof(kal_uint32);
	ptr_temp = ptr;
	for( i = 0; i < GPIONameLength_ut_val ; i++){
		if ( *ptr_temp != GPIOName_string_ut_val[i])	
		{
			ASSERT(0);
			//wrong LV[0] V
		}
		ptr_temp++;
	}
    
	ptr += GPIONameLength_ut_val;
    if (*ptr != sizeof(kal_uint32))	
	{
		ASSERT(0);
		//wrong LV[1] L
	}	
    ptr += sizeof(kal_uint32);
    if (*ptr != GPIONameLength_ut_val)	
	{
        ASSERT(0);
		//wrong LV[1] V
	}


	ccci_rpc_ch.ccci_write_gpd = check_reload_read_gpd;
	ccci_rpc_send_cb(channel, p_ccci_DL_ior);


	//fill ior==============
	//CCCI_RPC_ENTER_CRITICAL_SECTION
    if (KAL_TRUE == kal_query_systemInit()){ // polling mode
    //in init - use pd
	    ior.first_gpd = ccci_rpc_ch.p_polling_gpd;
	    ior.last_gpd  = ccci_rpc_ch.p_polling_gpd;
    }
    else{ 
	//after init - use gpd
		if (rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_occupied == 0){
			ASSERT(0);
		}
		ior.first_gpd =  p_ccci_DL_ior->first_gpd;
		ior.last_gpd  =  p_ccci_DL_ior->last_gpd;
    }
	
	CCCIDEV_RST_CCCI_COMM_GPD_LIST(ior.first_gpd,ior.last_gpd); 	

    //already get gpd
	/* Exit critical section */ 
	//CCCI_RPC_EXIT_CRITICAL_SECTION
	//get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(ior.first_gpd);
	//asign used gpd index
	temp_rpc_buffer->ccci_header.reserved = gpio_getpin_used_gpd_idx_ut_val;
    temp_rpc_buffer->ccci_header.channel = ccci_rpc_ch.receive_channel;
	temp_rpc_buffer->ccci_header.data[1] = 4*sizeof(kal_uint32);
	//copy opid, number of LV, LV[]  into ccci data field
	temp_rpc_buffer->rpc_opid = (IPC_RPC_API_RESP_ID |IPC_RPC_GPIO_GETPIN_OP_ut_val);
	temp_rpc_buffer->num_para = GPIONumOutputPar+1;  // "+1" is the return code LV pair
	
	//- point to LV[0]  
	ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);
    //asign LV[0]  : store return code
	*ptr = sizeof(kal_uint32);
	ptr += sizeof(kal_uint32);
	//*ptr = (void *)GPIOPin_ut_val;
    *((kal_uint32 *)ptr) = 1;  // return code >0 means RPC success 
	//- point to LV[1]
	ptr += sizeof(kal_uint32);
	//asign LV[1]
	*((kal_uint32 *)ptr) = sizeof(kal_uint32);
	ptr += sizeof(kal_uint32);
	//*ptr = (void *)GPIOPin_ut_val;
    *((kal_uint32 *)ptr) = (kal_uint32)GPIOPin_ut_val;

	// recieving path test
	// recieve call back function
	ccci_rpc_receive_cb(ccci_rpc_ch.receive_channel , &ior);
	if(ccci_rpc_ch.check_kal_systemInit() == KAL_TRUE){
	    ccci_rpc_ch.p_polling_gpd = ior.first_gpd;
	}



	return CCCI_SUCCESS;
}

kal_bool ccci_rpc_ut_fake_gpio_getpin_ccci_rpc_whole_data_path(void){
	kal_uint32 GPIONameLength = GPIONameLength_ut_val;
	kal_uint32 GPIOPin; //unsigned char
	kal_int32 ret;
	kal_uint8 *GPIOName = GPIOName_ut_val;

    
    ret =  IPC_RPC_Wrapper(IPC_RPC_GPIO_GETPIN_OP_ut_val,		GPIONameLength,		(void *)GPIOName,
                           sizeof(kal_uint32), (void *)&GPIONameLength,	IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32),  (kal_uint32*)(&GPIOPin),			IPC_RPC_EOF_TERM_PATTERN);
    //if rpc correct, it will return nuber of input parameter
    return ret;
}

kal_bool ccci_rpc_ut_whole_data_path(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
	kal_int32 ret = 0;

	ccci_rpc_ch.ccci_write_gpd = ccci_rpc_ut_gpio_getpin_whole_path_ccci_write_gpd;
	ccci_rpc_ch.ut_flag = IPC_RPC_CCCI_WHOLE_PATH_UT;	

	ret = ccci_rpc_ut_fake_gpio_getpin_ccci_rpc_whole_data_path();

	ccci_rpc_ch.ut_flag = IPC_RPC_CCCI_WRITE_ONLY_UT;
	ccci_rpc_ch.ccci_write_gpd = ccci_write_gpd;
	if (ret > 0)
	{
	    return KAL_TRUE;
	}
	else
	{
	    return KAL_FALSE;
	}
     
}

//=====================
//1.5 ccci_rpc_ut_non_init
//=====================

kal_bool always_return_true_function(void){
    return KAL_TRUE;
} 

static kal_int32 ccci_rpc_ut_polling_io(CCCI_CHANNEL_T channel,qbm_gpd * p_gpd,kal_bool is_tx){
	pIPC_RPC_StreamBuffer_T temp_rpc_buffer;
	kal_uint8 * ptr;
	kal_uint8 * ptr_temp;
	kal_uint8 i;
	kal_uint8 GPIOName_string_ut_val[GPIONameLength_ut_val] = {GPIOName_string_contend};
    //for recieving
	ccci_io_request_t ior= {0};
    kal_uint32 ret=0, num;
	kal_uint32 init_GPIOPin = 7;
	kal_uint32 * GPIOPin; 
    num = GPIONumOutputPar;
    GPIOPin = &init_GPIOPin;
    if(is_tx == KAL_FALSE) // RX
	    return CCCI_SUCCESS;
	//get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(p_gpd);
    //copy opid, number of LV, LV[]  into ccci data field
   
   	if(temp_rpc_buffer->rpc_opid != IPC_RPC_GPIO_GETPIN_OP_ut_val)
	{
	  
		ASSERT(0);
		//wrong op
	    return CCCI_INVALID_PARAM;
	}
	if(temp_rpc_buffer->num_para!= GPIONumInputPar)
	{
	    ASSERT(0);
		//wrong number of LV pairs
	}
	//- point to LV[0]
    ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);
    if (*ptr != GPIONameLength_ut_val)	
	{
		ASSERT(0);
		//wrong LV[0] L
	}
    ptr += sizeof(kal_uint32);
	ptr_temp = ptr;
	for( i = 0; i < GPIONameLength_ut_val ; i++){
		if ( *ptr_temp != GPIOName_string_ut_val[i])	
		{
			ASSERT(0);
			//wrong LV[0] V
		}
		ptr_temp++;
	}
    
	ptr += GPIONameLength_ut_val;
    if (*ptr != sizeof(kal_uint32))	
	{
		ASSERT(0);
		//wrong LV[1] L
	}	
    ptr += sizeof(kal_uint32);
    if (*ptr != GPIONameLength_ut_val)	
	{
        ASSERT(0);
		//wrong LV[1] V
	}
	QBM_DES_SET_NEXT(p_gpd, NULL);
	p_gpd = NULL;

	//fill ior==============
    if (KAL_TRUE == ccci_rpc_ch.check_kal_systemInit()){ // polling mode
    //in init - use pd
	    ior.first_gpd = ccci_rpc_ch.p_polling_gpd;
	    ior.last_gpd  = ccci_rpc_ch.p_polling_gpd;
    }
    else{ 
	//after init - use gpd
		if (rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_occupied == 0){
			ASSERT(0);
		}
		rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_occupied = 1;        
		ior.first_gpd =  (qbm_gpd *)rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_ptr;
		ior.last_gpd  =  (qbm_gpd *)rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_ptr;
    }
	
	CCCIDEV_RST_CCCI_COMM_GPD_LIST(ior.first_gpd,ior.last_gpd); 	

    //already get gpd
	//get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(ior.first_gpd);
	//asign used gpd index
	temp_rpc_buffer->ccci_header.reserved = gpio_getpin_used_gpd_idx_ut_val;
    temp_rpc_buffer->ccci_header.channel = ccci_rpc_ch.receive_channel;
	temp_rpc_buffer->ccci_header.data[1] = 4*sizeof(kal_uint32);
	//copy opid, number of LV, LV[]  into ccci data field
	temp_rpc_buffer->rpc_opid = (IPC_RPC_API_RESP_ID |IPC_RPC_GPIO_GETPIN_OP_ut_val);
	temp_rpc_buffer->num_para = GPIONumOutputPar+1;  // "+1" is the return code LV pair
	
	//- point to LV[0]  
	ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);
    //asign LV[0]  : store return code
	*ptr = sizeof(kal_uint32);
	ptr += sizeof(kal_uint32);
	//*ptr = (void *)GPIOPin_ut_val;
    *((kal_uint32 *)ptr) = 1;  // return code >0 means RPC success 
	//- point to LV[1]
	ptr += sizeof(kal_uint32);
	//asign LV[1]
	*((kal_uint32 *)ptr) = sizeof(kal_uint32);
	ptr += sizeof(kal_uint32);
	//*ptr = (void *)GPIOPin_ut_val;
    *((kal_uint32 *)ptr) = (kal_uint32)GPIOPin_ut_val;

	// recieving path test
	// recieve call back function
	if(ccci_rpc_ch.check_kal_systemInit() == KAL_TRUE){
	    ccci_rpc_ch.p_polling_gpd = ior.first_gpd;
	}

	return CCCI_SUCCESS;

}
static kal_int32 ccci_rpc_ut_read_error_handling(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo){
    ASSERT(0);
}
extern kal_bool ccci_rpc_main(void);
kal_bool ccci_rpc_ut_non_init(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
	kal_int32 ret = 0;

	
	//for bullseye pass function coverage
	ccci_rpc_main();

	//replace check initial function with a always return true function
	ccci_rpc_ch.check_kal_systemInit = always_return_true_function;
	ccci_rpc_ch.ccci_rpc_polling_io = ccci_rpc_ut_polling_io;
	ccci_rpc_ch.ccci_write_gpd = ccci_rpc_ut_read_error_handling;
	ccci_rpc_ch.ut_flag = IPC_RPC_CCCI_WHOLE_PATH_UT;	

	ret = ccci_rpc_ut_fake_gpio_getpin_ccci_rpc_whole_data_path();

	ccci_rpc_ch.ut_flag = IPC_RPC_CCCI_WRITE_ONLY_UT;
	ccci_rpc_ch.ccci_rpc_polling_io = ccci_polling_io;
	ccci_rpc_ch.ccci_write_gpd = ccci_write_gpd;
	ccci_rpc_ch.check_kal_systemInit = kal_query_systemInit;


	if (ret > 0)
	{
	    return KAL_TRUE;
	}
	else
	{
	    return KAL_FALSE;
	}
     
}

//=====================
//1.6 ccci_rpc_ut_test_general_query
//=====================
#define CCCI_RPC_UT_OP_ID 0xAAAA
#define general_query_buffer_length 13
#define general_query_buffer_value "Hello World!"
#define general_query_length 50
#define general_query_var1   0xAA
#define general_query_var2   0xAABB
#define general_query_var3   0xAABBCCDD

typedef struct CCCI_RPC_UT_INPUT_T{
	kal_uint32 length;
    kal_uint8  buffer[general_query_buffer_length];
    kal_uint8  var1;
    kal_uint16 var2;
    kal_uint32 var3;
}CCCI_RPC_UT_INPUT;

typedef struct CCCI_RPC_UT_RESULT_T{
	kal_uint32 length;
    kal_uint8  buffer[general_query_buffer_length];
    kal_uint8  var1;
    kal_uint16 var2;
    kal_uint32 var3;
}CCCI_RPC_UT_RESULT;


static kal_int32 ccci_rpc_ut_general_query_ccci_write_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo)
{
	pIPC_RPC_StreamBuffer_T temp_rpc_buffer;
	kal_uint8 * ptr;
	kal_uint8 * ptr_temp;
	kal_uint8 i;
    kal_uint8 buffer_value[] = general_query_buffer_value;
	CCCI_RPC_UT_INPUT *input;
    CCCI_RPC_UT_RESULT *output;
	CCCI_RPC_UT_INPUT  input_temp;
    //for recieving
	ccci_io_request_t ior= {0};
	

	//get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(p_ccci_DL_ior->first_gpd);
    //copy opid, number of LV, LV[]  into ccci data field

	// check op id
   	if(temp_rpc_buffer->rpc_opid != CCCI_RPC_UT_OP_ID)
	{
		ASSERT(0);
		//wrong op
	    return CCCI_INVALID_PARAM;
	}
    // check input para, only one struct
	if(temp_rpc_buffer->num_para!= 1)
	{
	    ASSERT(0);
		//wrong number of LV pairs
	}
	//- point to LV[0]
    ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);

	// check struct length
    if (*ptr != sizeof(CCCI_RPC_UT_INPUT))	
	{
		ASSERT(0);
		//wrong LV[0] L
	}
    ptr += sizeof(kal_uint32);
    input = (CCCI_RPC_UT_INPUT*) ptr;
    if (input->length != general_query_buffer_length)	
	{
		ASSERT(0);
		//wrong LV[0] L
	}

	ptr_temp = input->buffer;
	for( i = 0; i < general_query_buffer_length ; i++){
		if ( *ptr_temp != buffer_value[i])	
		{
			ASSERT(0);
		}
		ptr_temp++;
	}
    
    if (input->var1 != general_query_var1)	
	{
		ASSERT(0);
	}	
    
	if (input->var2 != general_query_var2)	
	{
		ASSERT(0);
	}	

	if (input->var3 != general_query_var3)	
	{
		ASSERT(0);
	}	
	input_temp.length = input->length;
    strncpy((char*)input_temp.buffer, (char*)input->buffer, general_query_buffer_length);
	input_temp.var1 = input->var1;
	input_temp.var2 = input->var2;
	input_temp.var3 = input->var3;

	ccci_rpc_ch.ccci_write_gpd = check_reload_read_gpd;
	ccci_rpc_send_cb(channel, p_ccci_DL_ior);


	//fill ior==============
	//CCCI_RPC_ENTER_CRITICAL_SECTION
    if (KAL_TRUE == kal_query_systemInit()){ // polling mode
    //in init - use pd
	    ior.first_gpd = ccci_rpc_ch.p_polling_gpd;
	    ior.last_gpd  = ccci_rpc_ch.p_polling_gpd;
    }
    else{ 
	//after init - use gpd
		if (rpc_gpd_pool[gpio_getpin_used_gpd_idx_ut_val].gpd_occupied == 0){
			ASSERT(0);
		}
		ior.first_gpd =  p_ccci_DL_ior->first_gpd;
		ior.last_gpd  =  p_ccci_DL_ior->last_gpd;
    }
	
	CCCIDEV_RST_CCCI_COMM_GPD_LIST(ior.first_gpd,ior.last_gpd); 	

    //already get gpd
	/* Exit critical section */ 
	//CCCI_RPC_EXIT_CRITICAL_SECTION
	//get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(ior.first_gpd);
	//asign used gpd index
	temp_rpc_buffer->ccci_header.reserved = 1; //first gpd pool
    temp_rpc_buffer->ccci_header.channel = ccci_rpc_ch.receive_channel;
	temp_rpc_buffer->ccci_header.data[1] = 2*sizeof(kal_uint32) + sizeof(CCCI_RPC_UT_RESULT);
	//copy opid, number of LV, LV[]  into ccci data field
	temp_rpc_buffer->rpc_opid = (IPC_RPC_API_RESP_ID | CCCI_RPC_UT_OP_ID);
	temp_rpc_buffer->num_para = 2;  // only 1 output struct+length
	
	//- point to LV[0]  
	ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);
    //asign LV[0]  : store return code
	*ptr = sizeof(kal_uint32);
	ptr += sizeof(kal_uint32);
    *((kal_uint32 *)ptr) = 1;  // return code >0 means RPC success 
	ptr += sizeof(kal_uint32);
	//asign LV[1]  : result
	*((kal_uint32 *)ptr) = sizeof(CCCI_RPC_UT_RESULT);
	ptr += sizeof(kal_uint32);

	// copy same 
	output = (CCCI_RPC_UT_RESULT*) ptr;
	output->length = input_temp.length;
    strncpy((char*)output->buffer, (char*)input_temp.buffer, general_query_buffer_length);
	output->var1 = input_temp.var1;
	output->var2 = input_temp.var2;
	output->var3 = input_temp.var3;

	// recieving path test
	// recieve call back function
	ccci_rpc_receive_cb(ccci_rpc_ch.receive_channel , &ior);
	if(ccci_rpc_ch.check_kal_systemInit() == KAL_TRUE){
	    ccci_rpc_ch.p_polling_gpd = ior.first_gpd;
	}

	return CCCI_SUCCESS;
}


kal_bool ccci_rpc_ut_test_general_query(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
	kal_int32 ret = 0;
	kal_int32 i = 0;
    CCCI_RPC_UT_INPUT input;  
    CCCI_RPC_UT_RESULT output;
	kal_uint8 buffer_value[] = general_query_buffer_value;
	kal_uint8 *ptr_temp;
	input.length = general_query_buffer_length;
    strncpy((char*)input.buffer, buffer_value, general_query_buffer_length);
	input.var1 = general_query_var1;
    input.var2 = general_query_var2;
	input.var3 = general_query_var3; 
    
	ccci_rpc_ch.ccci_write_gpd = ccci_rpc_ut_general_query_ccci_write_gpd;
	ccci_rpc_ch.ut_flag = IPC_RPC_CCCI_WHOLE_PATH_UT;	

	ret = IPC_RPC_General_Query(CCCI_RPC_UT_OP_ID, (void *) &input, sizeof(CCCI_RPC_UT_INPUT), (void *) &output, sizeof(CCCI_RPC_UT_RESULT));

	// check output 
	if(output.length != general_query_buffer_length){
		ASSERT(0);
	}
	ptr_temp = output.buffer;
	for( i = 0; i < general_query_buffer_length ; i++){
		if ( *ptr_temp != buffer_value[i])	
		{
			ASSERT(0);
		}
		ptr_temp++;
	}
	if (output.var1 != general_query_var1)	
	{
		ASSERT(0);
	}	
    
	if (output.var2 != general_query_var2)	
	{
		ASSERT(0);
	}	

	if (output.var3 != general_query_var3)	
	{
		ASSERT(0);
	}	
	
	// set ccci_write_gpd to default
	ccci_rpc_ch.ut_flag = IPC_RPC_CCCI_WRITE_ONLY_UT;
	ccci_rpc_ch.ccci_write_gpd = ccci_write_gpd;

	if (ret > 0)
	{
	    return KAL_TRUE;
	}
	else
	{
	    return KAL_FALSE;
	}
}



#ifdef ATEST_SYS_CCCI_RPC
extern kal_bool st_reg_test(kal_char *p_mod_name, ST_TCASE_T *p_tcase, kal_uint32 tcase_num);

ST_TCASE_T st_tcase_ccci_rpc_g[] = {
    {"1.1 ccci_rpc_ut_init_test",				ccci_rpc_ut_init_test,			NULL}, 
    {"1.2 ccci_rpc_ut_send",					ccci_rpc_ut_send,            	NULL},
    {"1.3 ccci_rpc_ut_read",					ccci_rpc_ut_read,            	NULL},
	{"1.4 ccci_rpc_ut_whole_data_path",			ccci_rpc_ut_whole_data_path, 	NULL},
	{"1.5 ccci_rpc_ut_non_init",				ccci_rpc_ut_non_init,		  	NULL},
	{"1.6 ccci_rpc_ut_test_general_query",		ccci_rpc_ut_test_general_query,	NULL},

};
kal_uint32 st_tcase_count_ccci_rpc_g = sizeof(st_tcase_ccci_rpc_g) / sizeof(ST_TCASE_T);

kal_bool ccci_rpc_ut_st_create()
{
    return st_reg_test("CCCI_RPC", st_tcase_ccci_rpc_g, st_tcase_count_ccci_rpc_g);
}
#endif

#endif //  __CCCI_RPC_UT__


//RPC usage for reference

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
#endif


//IPC ut for reference

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
#ifdef __SDIOC_PULL_Q_ENH_DL__
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

