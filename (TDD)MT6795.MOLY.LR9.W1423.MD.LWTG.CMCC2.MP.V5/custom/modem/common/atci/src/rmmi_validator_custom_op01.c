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
 * RMMI_VALIDATOR_CUSTOM_OP01.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for implementing custom commands for some customers
 *   which should not be released to other customers
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include <stdio.h>
#include <string.h>
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#ifdef __OP01__
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
//#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"
#include "event_shed.h"
#include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"

#include "l4c_common_enum.h"
//#include "mcd_l4_common.h"
#include "l4c_aux_struct.h"

//#include "l4c_rspfmttr.h"
#include "l4c_sendmsg.h"
#ifdef __MOD_SMU__
#include "ps2sim_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#endif /* __MOD_SMU__ */
#include "csmcc_atfunc.h"
#include "csmcc_common_enums.h"
#include "csmss_atfunc.h"
#include "csmss_common_enums.h"
#include "rmmi_common_enum.h"
#include "rmmi_context.h"
//#include "l4c_context.h"
#include "layer4_context.h"
#include "l4c_nw_cmd.h"
#include "l4c_eq_cmd.h"
#include "l4c2smsal_struct.h"
#include "l4crac_enums.h"
#include "l3_inc_enums.h"
#include "rmmi_rspfmttr.h"
#include "rmmi_msghdlr.h"
#include "rmmi_custom_parser.h"
#include "rmmi_utility.h"
#include "device.h"
#include "uem_context.h" 
#include "custom_equipment.h"
#include "kbd_table.h"
#include "nvram_struct.h"
#include "nvram_interface.h"
#include "uem_proc_cmd.h"
#include "uem_utility.h"
#include "bmt.h"
//#include "l4a.h"
#include "custom_nvram_extra.h"
#include "l4c_utility.h"
#include "rmmi_custom_inc.h"
//#include "aud_defs.h" 
//#include "lcd_if.h"
//#include "mtcdef.h"
#include "csmcc_atfunc.h"
#include "l4_trc.h"
#include "l4c_sim_cmd.h"

/*****************************************************************************
 * FUNCTION
 *  rmmi_dsci_hdlr
 * DESCRIPTION
 *  This function handles the AT^DSCI input String
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_dsci_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 buffer[RMMI_SHORT_RSP_LEN];
    kal_uint8 string_length = 0;

    switch (source_string_ptr->cmd_mode)
    {
        case RMMI_READ_MODE: /* AT^DSCI? */
        {
	        RMMI_PTR->arg_list[0] = (void*)&(RMMI_PTR->op01_report_mode.dsci);
            string_length = rmmi_fast_string_print(buffer, (kal_uint8*) "^DSCI: %d", RMMI_PTR->arg_list, 1);
            ret_val = KAL_TRUE;
            break;
        }
        case RMMI_SET_OR_EXECUTE_MODE: /* AT^DSCI=<1 or 0> */
        {
	        kal_uint8 mode;

            mode = (kal_uint8) rmmi_int_validator_range_check(NULL, 
                                                              source_string_ptr, 
                                                              (kal_uint8) RMMI_PTR->s_reg.s3,
                                                              1);
            if (mode != RMMI_VALIDATOR_ERROR)
            {
                ret_val = KAL_TRUE;
                RMMI_PTR->op01_report_mode.dsci = mode;
            }
            break;
        }
        default:
            break;
    }
    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, buffer, string_length);
}


/*****************************************************************************
 * FUNCTION
 *  rmmi_mtv_hdlr
 * DESCRIPTION
 *  This function handles the AT^MTV input String
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_mtv_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 buffer[RMMI_SHORT_RSP_LEN];
    kal_uint8 string_length = 0;
#ifdef __CMMB_SUPPORT__
    const kal_uint8 mtv_func = 1;
#else
    const kal_uint8 mtv_func = 0;
#endif
#ifdef __CMMB_CAS_MBBMS_SUPPORT__
    const kal_uint8 mbbms_func = 1;
#else
    const kal_uint8 mbbms_func = 0;
#endif

    switch (source_string_ptr->cmd_mode)
    {
        case RMMI_READ_MODE: /* AT^MTV? */
        {
	        RMMI_PTR->arg_list[0] = (void*)&(mtv_func);
            RMMI_PTR->arg_list[1] = (void*)&(mbbms_func);
            string_length = rmmi_fast_string_print(buffer, (kal_uint8*) "^MTV: %d, %d", RMMI_PTR->arg_list, 2);
            ret_val = KAL_TRUE;
            break;
        }
        default:
            break;
    }
    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, buffer, string_length);
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_sysinfo_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_sysinfo_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 const *rsp_str = NULL;
    kal_uint8 buffer[RMMI_SHORT_RSP_LEN];
    kal_uint16 string_length = 0;    
    
    switch (source_string_ptr->cmd_mode)
    {  
        case RMMI_ACTIVE_MODE:
        {
            kal_uint8 cs_service, mobile_class;
            kal_uint8 srv_status=0, srv_domain=0, roam_status=0, sys_mode=0, sim_state=0,sys_submode=0;
            kal_bool is_on_hplmn;

            // srv_status
            l4c_nw_get_attach_status_req(source_string_ptr->src_id, RAC_CS, &cs_service);
            if (l4c_check_state_is_registered(cs_service) != KAL_TRUE)
            {
                srv_status = 1;
            }
            else
            {
                srv_status = 2;            
            }

            if (l4c_get_cfun_state() != 1)
            {
                srv_status = 0;
            }

            // srv_domain
            l4c_nw_get_class_req(source_string_ptr->src_id, &mobile_class);
            if (mobile_class == 0 || mobile_class == 1) // A , B
            {
                srv_domain = 3;  // CS+PS
            }
            else if (mobile_class == 2) // CG
            {
                srv_domain = 2;  // PS only
            }
            else if (mobile_class == 3) // CC
            {
                srv_domain = 1;  // CS only
            }            

            // roam_status
            l4c_nw_get_romaing_status_req(source_string_ptr->src_id, &is_on_hplmn);
            roam_status= (is_on_hplmn?0:1);

            // sys_mode
            switch(RMMI_PTR->cs_register_status.act)
            {
                case 0:
                case 1:
                case 3:
                    sys_mode = 3;
                    break;
                case 2:
                case 4:
                case 5:
                case 6:
                #ifdef __UMTS_TDD128_MODE__
                    sys_mode = 15;
                #else
                    sys_mode = 5;
                #endif
                    break;
                default:
                    ASSERT(0);
                    break;
            }

            // sim_state
            if (l4c_get_sim_status() == L4C_SIM_INSERTED)
            {
                if (is_sim_verified() == KAL_FALSE)
                {
                    sim_state = 255;
                }
                else
                {
                    if (srv_status == 2)
                    {
                        sim_state = 1;
                    }
                    else
                    {
                        sim_state = 0;
                    }
                }
            }
            else
            {
                sim_state = 255;
                roam_status = 0;
            }

            // sys_submode
            switch(RMMI_PTR->cs_register_status.act)
            {
                case 0:
                case 1:
                    sys_submode = 2;
                    break;
                case 3:
                    sys_submode = 3;
                    break;
                case 2:
                    sys_submode = 4;
                    break;
            #if defined(__UMTS_TDD128_MODE__)
                case 4:
                case 5:
                case 6:
                    sys_submode = 8;
                    break;
            #else
                case 4:
                    sys_submode = 5;
                    break;
                case 5:
                    sys_submode = 6;
                    break;
                case 6:
                    sys_submode = 7;
                    break;
            #endif
                default:
                    ASSERT(0);
                    break;
            }

            if (srv_status != 2)
            {
                srv_domain = 0;
                roam_status= 0;
                sys_mode = 0;
                sys_submode = 0;
            }

            RMMI_PTR->arg_list[0] = (void*)&srv_status;
            RMMI_PTR->arg_list[1] = (void*)&srv_domain;
            RMMI_PTR->arg_list[2] = (void*)&roam_status;
            RMMI_PTR->arg_list[3] = (void*)&sys_mode;
            RMMI_PTR->arg_list[4] = (void*)&sim_state;
            RMMI_PTR->arg_list[5] = (void*)&sys_submode;
            string_length = rmmi_fast_string_print(buffer, (kal_uint8*) "^SYSINFO:%d,%d,%d,%d,%d,,%d", RMMI_PTR->arg_list, 6);

            ret_val = KAL_TRUE;
            break;
        }
        default:
            break;
    }
    
    rsp_str = &buffer[0];    
    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8*) rsp_str, string_length);
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_sysconfig_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_sysconfig_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 error_cause;
    kal_uint8 const *rsp_str = NULL;
    kal_uint8 buffer[RMMI_SHORT_RSP_LEN];
    kal_uint16 string_length = 0;    

    switch (source_string_ptr->cmd_mode)
    {
        case RMMI_READ_MODE:
        {
            kal_uint8 mode, acqorder, roam, srv_domain;
            kal_uint8 rat_mode, prefer_rat, mobile_class;
            kal_bool support_roaming;

            // mode
            ret_val = l4c_nw_get_rat_mode_req(source_string_ptr->src_id, &rat_mode);
            if (rat_mode == L4C_RAT_GSM)
            {
                mode = 13;
            }
            else if (rat_mode == L4C_RAT_UMTS)
            {
            #if defined(__UMTS_TDD128_MODE__)
                mode = 15;
            #else
                mode = 14;
            #endif
            }
            else
            {
                mode = 2;
            }

            // acqorder
            ret_val = l4c_nw_get_prefer_rat_req(&prefer_rat);
            if (prefer_rat == RAT_GSM)
            {
                acqorder = 1;
            }
            else if (prefer_rat == RAT_UMTS)
            {
                acqorder = 2;
            }
            else
            {
                acqorder = 0;
            }

            // roam
            ret_val = l4c_nw_get_romaing_mode_req(source_string_ptr->src_id, &support_roaming);
            if (support_roaming == KAL_TRUE)
            {
                roam = 1;
            }
            else
            {
                roam = 0;
            }

            // srvdomain
            ret_val = l4c_nw_get_class_req(source_string_ptr->src_id, &mobile_class);
            if (mobile_class == 0 || mobile_class == 1) // A , B
            {
                srv_domain = 2;  // CS+PS
            }
            else if (mobile_class == 2) // CG
            {
                srv_domain = 1;  // PS only
            }
            else if (mobile_class == 3) // CC
            {
                srv_domain = 0;  // CS only
            }
            else
            {
                srv_domain = 3; // Any
            }

            RMMI_PTR->arg_list[0] = (void*)&mode;
            RMMI_PTR->arg_list[1] = (void*)&acqorder;
            RMMI_PTR->arg_list[2] = (void*)&roam;
            RMMI_PTR->arg_list[3] = (void*)&srv_domain;
            string_length = rmmi_fast_string_print(buffer, (kal_uint8*) "^SYSCONFIG:%d,%d,%d,%d", RMMI_PTR->arg_list, 4);

            ret_val = KAL_TRUE;
            break;
        }
        case RMMI_SET_OR_EXECUTE_MODE:
        {
            kal_uint8 mode, acqorder, roam, srv_domain;
            kal_uint8 rat_mode, prefer_rat, mobile_class;
            kal_bool support_roaming=KAL_TRUE;

            mode = rmmi_int_validator_u8_check(
                                    &error_cause,
                                    source_string_ptr,
                                    (kal_uint8) RMMI_COMMA);

	     if (error_cause != RMMI_PARSE_OK)
	     {
		  if (error_cause == RMMI_PARSE_NOT_FOUND)
		  {
			mode = 16; // unchanged
		  }
		  else
		  {
		  	break;		  
		  }
	     }
        #if defined(__UMTS_TDD128_MODE__)
            else
            {
                if (mode == 14)
                {
                    break;
                }
            }
        #endif

            acqorder = (kal_uint8)rmmi_int_validator_range_check(
                                    &error_cause,
                                    source_string_ptr,
                                    (kal_uint8) RMMI_COMMA,
                                    3);

	     if (error_cause != RMMI_PARSE_OK)
	     {
		  if (error_cause == RMMI_PARSE_NOT_FOUND)
		  {
			acqorder = 3; // unchanged
		  }
		  else
		  {
		  	break;		  
		  }
	     }

            roam = (kal_uint8)rmmi_int_validator_range_check(
                                    &error_cause,
                                    source_string_ptr,
                                    (kal_uint8) RMMI_COMMA,
                                    2);

	     if (error_cause != RMMI_PARSE_OK)
	     {
		  if (error_cause == RMMI_PARSE_NOT_FOUND)
		  {
			roam = 2; // unchanged
		  }
		  else
		  {
		  	break;		  
		  }
	     }

            srv_domain = (kal_uint8)rmmi_int_validator_range_check(
                                    &error_cause,
                                    source_string_ptr,
                                    (kal_uint8) RMMI_COMMA,
                                    4);

	     if (error_cause != RMMI_PARSE_OK)
	     {
		  if (error_cause == RMMI_PARSE_NOT_FOUND)
		  {
			srv_domain = 4; // unchanged
		  }
		  else
		  {
		  	break;		  
		  }
	     }

            // Do nothing if totally unchaged
            if (mode == 16 && acqorder == 3 && roam ==2 && srv_domain == 4)  
            {
                ret_val = KAL_TRUE;
                break;
            }

            // rat_mode
            if (mode == 13)
            {
                rat_mode = RAT_GSM;
            }
            else if (mode == 14 || mode == 15)
            {
                rat_mode = RAT_UMTS;
            }
            else if (mode == 16)
            {
                l4c_nw_get_rat_mode_req(source_string_ptr->src_id, &rat_mode); // unchange
            }
            else 
            {
                rat_mode = RAT_GSM_UMTS;
            }

            // prefer_rat
            if (acqorder == 1)
            {
                prefer_rat = RAT_GSM;
            }
            else if (acqorder == 2)
            {
                prefer_rat = RAT_UMTS;
            }
            else if (acqorder == 3)
            {
                l4c_nw_get_prefer_rat_req(&prefer_rat); // do not change
            }
            else
            {
                prefer_rat = RAT_GSM_UMTS;
            }

            // support_roaming
            if (roam == 0)
            {
                support_roaming = KAL_FALSE;
            }
            else if (roam == 1)
            {
                support_roaming = KAL_TRUE;
            }
            else
            {
                l4c_nw_get_romaing_mode_req(source_string_ptr->src_id, &support_roaming);  // do not change
            }

            // mobile_class
            if (srv_domain == 0)
            {
                mobile_class = 3; // CS only
            }
            else if (srv_domain == 1)
            {          
                mobile_class = 2; // PS only
            }
            else if (srv_domain == 4)
            {
                l4c_nw_get_class_req(source_string_ptr->src_id, &mobile_class); // unchange
            }
            else if (srv_domain >= 2)
            {
                mobile_class = 1; // CS_PS
            }

            ret_val = l4c_nw_set_sysconfig_req(source_string_ptr->src_id, rat_mode, prefer_rat, support_roaming, mobile_class);
            if (ret_val ==KAL_TRUE)
            {
                return;
            }
        }
        default:
            break;
    }

    rsp_str = &buffer[0];        
    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8*) rsp_str, string_length);
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_cardmode_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_cardmode_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 const *rsp_str = NULL;
    kal_uint8 buffer[RMMI_SHORT_RSP_LEN];
    kal_uint16 string_length = 0;  

    switch (source_string_ptr->cmd_mode)
    {
        case RMMI_READ_MODE:
        {
            int sim_state=0;

            if (is_sim_verified() == KAL_FALSE)
            {
                sim_state = 255;
            }
            else
            {
                if (check_is_usim() == KAL_TRUE)
                {
                    sim_state = 2;
                }
                else
                {
                    sim_state = 1;
                }
            }

            RMMI_PTR->arg_list[0] = (void*)&sim_state;            
            string_length = rmmi_fast_string_print(buffer, (kal_uint8*) "^CARDMODE: %d", RMMI_PTR->arg_list, 1);
            ret_val = KAL_TRUE;
            break;
        }
        case RMMI_SET_OR_EXECUTE_MODE:
        {
            kal_uint8 mode, error_cause;

            mode = (kal_uint8) rmmi_int_validator_range_check(&error_cause, source_string_ptr, RMMI_PTR->s_reg.s3, 1);
            if (error_cause != RMMI_PARSE_OK)
            {
                break;
            }

            RMMI_PTR->op01_report_mode.cardmode = mode;
            ret_val = KAL_TRUE;
            break;
        }
        default:
            break;
    }
    
    rsp_str = &buffer[0];      
    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8*) rsp_str, string_length);
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_rfsw_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_rfsw_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 const *rsp_str = NULL;
    kal_uint8 buffer[RMMI_SHORT_RSP_LEN];
    kal_uint16 string_length = 0;  

    switch (source_string_ptr->cmd_mode)
    {
        case RMMI_READ_MODE:
        {
            int state;

            if (l4c_get_cfun_state() != 1)
            {
                state = 0;
            }
            else
            {
                state = 1;
            }
            
            RMMI_PTR->arg_list[0] = (void*)&state;            
            string_length = rmmi_fast_string_print(buffer, (kal_uint8*) "^RFSW: %d", RMMI_PTR->arg_list, 1);
            ret_val = KAL_TRUE;              
            break;
        }
        case RMMI_SET_OR_EXECUTE_MODE:
        {
            kal_uint8 value, error_cause;

            value = (kal_uint8) rmmi_int_validator_range_check(&error_cause, source_string_ptr, RMMI_PTR->s_reg.s3, 1);
            if (error_cause != RMMI_PARSE_OK)
            {
                break;
            }

            RMMI_PTR->op01_report_mode.rfsw = value;
            ret_val = KAL_TRUE;
            break;
        }
        default:
            break;
    }
    
    rsp_str = &buffer[0];      
    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8*) rsp_str, string_length);
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_spn_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_spn_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 error_cause;
    kal_uint8 const *rsp_str = NULL;
    kal_uint8 buffer[RMMI_SHORT_RSP_LEN];
    kal_uint16 string_length = 0;  

    switch (source_string_ptr->cmd_mode)
    { 
        case RMMI_SET_OR_EXECUTE_MODE:
        {
            kal_uint8 spn_type;
            kal_uint8 PATH_SPN[6] = {0x7F,0x20,0x6F,0x46,0x00,0x00};
            kal_uint8 PATH_U_SPN[6] = {0x7F,0xFF,0x6F,0x46,0x00,0x00};

            spn_type = (kal_uint8) rmmi_int_validator_range_check(&error_cause, source_string_ptr, RMMI_PTR->s_reg.s3, 1);
            if (error_cause != RMMI_PARSE_OK)
            {
                break;
            }

            if (spn_type == 0)
            {   // Read SIM SPN
                ret_val = l4c_smu_read_file_info_req(source_string_ptr->src_id, FILE_NONE, PATH_SPN, 0);
            }
            else
            {   // Read USIM SPN
                ret_val = l4c_smu_read_file_info_req(source_string_ptr->src_id, FILE_NONE, PATH_U_SPN, 1);            
            }

            if (ret_val == KAL_TRUE)
            {
                return;
            }
            break;
        }
        default:
            break;
    }
    
    rsp_str = &buffer[0];      
    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8*) rsp_str, string_length);
}


/*****************************************************************************
 * FUNCTION
 *  rmmi_hver_hdlr
 * DESCRIPTION
 *  This command is for CMCC test, and used to get hardware version.
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
 void rmmi_hver_hdlr(rmmi_string_struct *source_string_prt)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint16 string_length = 0;
    kal_uint8 const *rsp_str = NULL;
    kal_uint8 eq_id[NVRAM_EF_BARCODE_NUM_SIZE + 1];
    kal_uint8 buffer[MAX_UART_LENGTH];
    
    //kal_trace(TRACE_FUNC, FUNC_RMMI_HVER_HDLR_ENTRY);//change to kal_brief_trace?
    switch(source_string_prt->cmd_mode)
    {
        case RMMI_ACTIVE_MODE:
        {
            /* Get Base band chip version, same as AT+EGMR=0,0 */
            ret_val = get_ms_revision(0, (kal_uint8*)eq_id);
            if(ret_val == KAL_TRUE)
            {
                RMMI_PTR->arg_list[0] = (void*)eq_id;
                string_length = rmmi_fast_string_print(buffer,
                                                       (kal_uint8*) "^HVER: \"%s\"",
                                                       RMMI_PTR->arg_list,
                                                       1);
                rsp_str = &buffer[0];
            }
            break;
        }
        default:
        {
            /* Unrecognized command format */
            break;
        }
        
    }
    rmmi_final_rsp_generator(source_string_prt->src_id, ret_val, (kal_uint8*)rsp_str, string_length);
}


/*****************************************************************************
 * FUNCTION
 *  rmmi_cmdver_hdlr
 * DESCRIPTION
 *  This command is for CMCC test, and used to get AT CMD version.
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_cmdver_hdlr(rmmi_string_struct *source_string_prt)
{
    kal_uint8 main_ver = CMCC_AT_CMD_MAIN_VER;
    kal_uint8 major_ver = CMCC_AT_CMD_MAJOR_VER;
    kal_uint8 minor_ver = CMCC_AT_CMD_MINOR_VER;
    kal_bool ret_val = KAL_FALSE;
    kal_uint16 string_length = 0;
    kal_uint8 const *rsp_str = NULL;
    kal_uint8 buffer[MAX_UART_LENGTH];
    
    //kal_trace(TRACE_FUNC, FUNC_RMMI_CMDVER_HDLR_ENTRY);//change to brief trace?
    switch(source_string_prt->cmd_mode)
    {
        case RMMI_ACTIVE_MODE:
        {
            RMMI_PTR->arg_list[0] = (void*)&main_ver;
            RMMI_PTR->arg_list[1] = (void*)&major_ver;
            RMMI_PTR->arg_list[2] = (void*)&minor_ver;
            string_length = rmmi_fast_string_print(buffer,
                                                   (kal_uint8*) "^CMDVER: %d,%d,%d",
                                                   RMMI_PTR->arg_list,
                                                   3);
            rsp_str = &buffer[0];
            ret_val = KAL_TRUE;
            break;
        }
         
        default:
        {
            /* Unrecognized command format */
            break;
        }
        
    }
    rmmi_final_rsp_generator(source_string_prt->src_id, ret_val, (kal_uint8*)rsp_str, string_length);
}


/*****************************************************************************
 * FUNCTION
 *  rmmi_off_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_off_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 const *rsp_str = NULL;
    kal_uint8 buffer[RMMI_SHORT_RSP_LEN];
    kal_uint16 string_length = 0;  

    switch (source_string_ptr->cmd_mode)
    {
        case RMMI_ACTIVE_MODE:
        {
            ret_val = l4c_nw_cfun_state_req(source_string_ptr->src_id, 4);
            if (ret_val == KAL_TRUE)
            {
                return;
            }
            break;
        }
        default:
            break;
    }
    
    rsp_str = &buffer[0];      
    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8*) rsp_str, string_length);
}

#endif
