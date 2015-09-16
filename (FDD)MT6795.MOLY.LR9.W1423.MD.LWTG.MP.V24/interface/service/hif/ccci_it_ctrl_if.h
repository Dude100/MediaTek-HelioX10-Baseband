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
 *   ccci_it_ctrl_if.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   The API header file of CCCI IT Mode Control.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * 03 27 2013 ap.wang
 * removed!
 *
 * 03 21 2013 ap.wang
 * removed!
 *
 * 03 18 2013 ap.wang
 * removed!
 * [CCCI_IT_CTRL] Add Downlink packet gen API
 *
 * 03 11 2013 ap.wang
 * removed!
 * [CCCI_IPC] Modify for IT Loopback and compile warning fix
 ****************************************************************************/
#ifndef __CCCI_IT_CTRL_IF_H__
#define __CCCI_IT_CTRL_IF_H__

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "ccci_if.h"


/*******************************************************************************
 * Data Structure Definition
 *******************************************************************************/

/*!
 *  @brief register information of a test module.
 *
 *  @param  p_ret_err_str     returned string of error description.
 *                            This string buffer is allocated by caller (sys_test) module,
 *                            and the callee module fills in error description in this buffer.
 *  @param  p_ret_err_str_sz  The caller module use this parameter to define the max size of error string buffer,
 *                            and the callee module fills in the actual size of error string buffer when returning.
 *                            Note: The callee module CAN NOT fill into 'p_ret_err_str' with exceeding size limit.
 *                                  Useful function : snprintf(p_err_str, p_err_str_sz, foramt_str, ...)
 */

typedef kal_bool (*it_mode_func)(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz);

typedef struct _IT_MODE_T {
    kal_char    *it_mode_description; /* string description of it mode function */ 
    it_mode_func    it_mode_func;     /* it mode function */
    void        *it_mode_func_param;  /* parameter of it mode function */
    kal_uint32  it_task_number;       /* number of task to execute this function - no use now */
} IT_MODE_T;

/*******************************************************************************
 * Public API
 *******************************************************************************/

/*!
 *  ccci_service_it_table_reg
 *  
 *  @brief register test function to SYS_TEST module.
 *
 *  @param  p_mod_name        test module naming.
 *  @param  p_tcase           test function information used to register.
 *  @param  tcase_num         number of test function struct.
 *
 *  @return kal_bool          KAL_TRUE if success, otherwise KAL_FALSE if fail.
 */
kal_bool ccci_it_mode_control_table_reg(kal_char *p_module_name, IT_MODE_T *p_mode, kal_uint32 mode_num);

/*!
 *  ccci_it_gen_packet
 *  
 *  @brief  Downlink packet GPD generator.
 *
 *  @param  type            qbm_gpd type of packet.
 *  @param  p_fun           generator function pointer.
 *
 *  @return kal_bool          KAL_TRUE if success, otherwise KAL_FALSE if fail.
 */
ccci_io_request_t ccci_it_gen_packet(qbm_type type);


/*!
 * Example usage:
 *
 * @code
 
 #include "ccci_service_it_if.h"
 
 IT_TEST_CASE_T it_function_table[]={
    {"IT function 1"}, it_function_1, NULL},
    {"IT function 2"}, it_function_2, NULL}
 }

 kal_bool "Module name"_it_create(){
    return ccci_service_it_table_reg("Module name", 
                                     it_function_table, 
                                     sizeof(it_function_table) / sizeof(IT_TEST_CASE_T) 
                                     );
 }
 
 * @endcode
 */

#endif //__CCCI_IT_CTRL_IF_H__
