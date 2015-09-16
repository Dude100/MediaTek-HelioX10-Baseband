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
 *   ccci_sys_msg.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implement the function for ccci system message hangling. 
 *   
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * 
 ****************************************************************************/

#include "ccci_if.h"
#include "kal_public_api.h"
#include "ccci_sys_msg.h"
#include "ps_public_l4_msgid.h"

#if defined(__SMART_PHONE_MODEM__) && defined(__HIF_CCIF_SUPPORT__) //router only
#include "sleepdrv_interface.h"
#endif

static CCCI_SYSMSGSVC_HISR_CALLBACK	ccci_sysmsgsvc_cb[CCMSG_ID_SYSMSGSVC_END - CCMSG_ID_SYSMSGSVC_START];
static ccci_sys_msg_inst_t ccci_sys_msg_inst;
#undef	X_CCCI_SYSMSGSVC_CONF
#define	X_CCCI_SYSMSGSVC_CONF(mSGNO, mODE, iD) {mODE, iD},
static kal_uint32 ccci_sysmsgsvc_msg[CCMSG_ID_SYSMSGSVC_END - CCMSG_ID_SYSMSGSVC_START][2] = { 
																									#include "ccci_sysmsgsvc_conf.h"
	                                                                                         };                                                                                
#undef	X_CCCI_SYSMSGSVC_CONF


/*******************************************************************************
 * Define functions.
 *******************************************************************************/


 /*************************************************************************
 * FUNCTION
 *  ccci_register_sysmsgsvc_callback
 *
 * DESCRIPTION
 *  To provide user to register system message callback function
 *
 * PARAMETERS
 *  msgno   -    message number
 *  funp    -    callback function
 *
 * RETURNS
 *  KAL_FALSE : Fail
 *  KAL_TURE  : Success
 *
 *************************************************************************/
 kal_int32 ccci_register_sysmsgsvc_callback(kal_uint32 msgno, CCCI_SYSMSGSVC_HISR_CALLBACK funp)
 {
     kal_uint32  value;
 
     if((msgno < CCMSG_ID_SYSMSGSVC_START) ||
        (msgno >= CCMSG_ID_SYSMSGSVC_END) ||
        (funp == NULL)) 
     {
        ccci_sys_msg_trace(CCCI_SYS_MSG_WARN, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_INVALID_PARM, msgno, funp);
        return KAL_FALSE;
     }
 
     value = msgno - CCMSG_ID_SYSMSGSVC_START;
 
     ccci_sysmsgsvc_cb[value] = funp;

     ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_REG_CB, msgno, funp);
     
     return KAL_TRUE;
 }


 /*************************************************************************
 * FUNCTION
 *  void ccci_system_channel_runtime_callback
 *
 * DESCRIPTION
 *  This function use to handle control channel messages from AP side
 *  major information : MDSC insert or remove message and change EINT poliaty
 *
 * PARAMETERS
 *  channel    -             logical channel
 *  *
 * RETURNS
 *  NA
 *
 *************************************************************************/
 void ccci_system_channel_runtime_callback(CCCI_BUFF_T *bufp)
 {
     kal_int32  ret;
     kal_uint32 id;
     kal_uint32 id_1;
 
 
     if(INT_QueryExceptionStatus() == KAL_TRUE) return;
     
     id = CCCI_MAILBOX_ID(bufp);

     if (id & CCMSG_ID_SYSMSGSVC_MASK)
     {
         if (id >= CCMSG_ID_SYSMSGSVC_END)
         {
            ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_INVALID_ID, id);
            return;
         }
             
         id_1 = id - CCMSG_ID_SYSMSGSVC_START;
                     
         if (ccci_sysmsgsvc_cb[id_1])
         {
             ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_INVK_CB, id);
             ccci_sysmsgsvc_cb[id_1](bufp->reserved);
 
             if (id == CCMSG_ID_SYSMSGSVC_L1_SLEEPMASKING)
             {
                 ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_SEND_SLEEPMASKING_MSG, bufp->reserved);
                 ret = ccci_sys_msg_inst.ccci_send_message(CCMSG_ID_SYSMSGSVC_L1_SLEEPMASKING, bufp->reserved);
                 if (ret == KAL_FALSE)
                 {
                     ccci_sys_msg_trace(CCCI_SYS_MSG_WARN, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_SLEEPMASKING);
                 }
             }
         }
         else
         {
            ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_INVALID_REG_CB, id);
         }
         
         //- ilm section
         if (ccci_sysmsgsvc_msg[id_1][0] & 0x80)
         {
             if (ccci_sysmsgsvc_msg[id_1][0] & 0x40)
             {
                 CCCI_COMMON_ILM_4B *local_para_4B;
                 local_para_4B = (CCCI_COMMON_ILM_4B *) construct_local_para (sizeof(CCCI_COMMON_ILM_4B), TD_RESET);
                 local_para_4B->W0 = bufp->reserved;
                 ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_SEND_ILM_D, ccci_sysmsgsvc_msg[id_1][1], bufp->reserved);
                 msg_send5 (CCCI_SYS_MSG_MOD, MOD_L4C, 0, ccci_sysmsgsvc_msg[id_1][1], (local_para_struct*)local_para_4B);
             }
             else
             {
                 ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_SEND_ILM, ccci_sysmsgsvc_msg[id_1][1]);
                 msg_send4 (CCCI_SYS_MSG_MOD, MOD_L4C, 0, ccci_sysmsgsvc_msg[id_1][1]);              
             }
         }
 
         return; 
     }
     
     switch(CCCI_MAILBOX_ID(bufp))
     {
     case  CCMSG_ID_MD_L4_MOD:
     {
         ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_SEND_ILM, MSG_ID_L4C_END_PS_DATA_SENSSION_REQ);
         msg_send4 (CCCI_SYS_MSG_MOD, MOD_L4C, 0, MSG_ID_L4C_END_PS_DATA_SENSSION_REQ);
     }
     break;
     case  CCMSG_ID_MD_L4_MAX_TX_PWR_RED_REQ:
     {
         CCCI_COMMON_ILM_2B *local_para;
 
         local_para = (CCCI_COMMON_ILM_2B *) construct_local_para (sizeof(CCCI_COMMON_ILM_2B), TD_RESET);
         local_para->HW0 = bufp->reserved & 0xFFFF;
         ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_SEND_ILM_D, MSG_ID_L4C_MAX_TX_PWR_RED_REQ, local_para->HW0);
         msg_send5 (CCCI_SYS_MSG_MOD, MOD_L4C, 0, MSG_ID_L4C_MAX_TX_PWR_RED_REQ, (local_para_struct*)local_para);
     }
     break;
     default:
         ccci_sys_msg_trace(CCCI_SYS_MSG_WARN, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_UNKNOW_MB_ID, CCCI_MAILBOX_ID(bufp));       
         break;
     }//end switch
 }

 void ccci_sys_msg_dlcb_dummy(CCCI_BUFF_T *bufp)
 {
     /* RT queue should not callback */
     ccci_sys_msg_trace(CCCI_SYS_MSG_ERR, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_ABNORMAL_DL_CB);
     ASSERT(KAL_FALSE);
     return;
 }

#if defined(__SMART_PHONE_MODEM__) && defined(__HIF_CCIF_SUPPORT__) //router only
 void ccci_md_sleep_control(kal_uint32 reserved)
 {
     // sleep handle
     static kal_uint8 CCCI_sleep_handle = 0xFF;
     
     //init, only do once
     if(0xFF == CCCI_sleep_handle)
     {
        CCCI_sleep_handle = SleepDrv_GetHandle();
     }

     switch(reserved)
     {
        case CCCI_MD_SLEEP_LOCK:
            ccci_sys_msg_trace(CCCI_SYS_MSG_ERR, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_CCCI_MD_SLEEP_LOCK, CCCI_sleep_handle);
            // Sleep Disable
            SleepDrv_SleepDisable(CCCI_sleep_handle);
            ccci_send_message(CCMSG_ID_SYSMSGSVC_MD_SLEEP_CONTROL, CCCI_ACK_DONE);
            break;
        case CCCI_MD_SLEEP_UNLOCK:
            ccci_sys_msg_trace(CCCI_SYS_MSG_ERR, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_CCCI_MD_SLEEP_UNLOCK, CCCI_sleep_handle);
            // Sleep Enable
            SleepDrv_SleepEnable(CCCI_sleep_handle);
            ccci_send_message(CCMSG_ID_SYSMSGSVC_MD_SLEEP_CONTROL, CCCI_ACK_DONE);
            break;
        default:
            ccci_sys_msg_trace(CCCI_SYS_MSG_ERR, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_CCCI_MD_SLEEP_INVALID, reserved);
            ASSERT(0);
            break;
     }
 }
#endif

 void ccci_sys_msg_svc_init()
 {
    kal_int32  ccci_ret;
	
    ccci_sys_msg_inst.ccci_init = ccci_init;
    ccci_sys_msg_inst.ccci_send_message = ccci_send_message;
    
    ccci_ret = ccci_sys_msg_inst.ccci_init(CCCI_SYSTEM_CHANNEL_ACK, ccci_system_channel_runtime_callback);
    ccci_sys_msg_trace(CCCI_SYS_MSG_ERR, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_UL_CHANNEL_INIT_RESULT, CCCI_SYSTEM_CHANNEL_ACK, ccci_ret);
    ASSERT(CCCI_SUCCESS == ccci_ret);
    
    ccci_ret = ccci_sys_msg_inst.ccci_init(CCCI_SYSTEM_CHANNEL, ccci_sys_msg_dlcb_dummy);
    ccci_sys_msg_trace(CCCI_SYS_MSG_ERR, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_DL_CHANNEL_INIT_RESULT, CCCI_SYSTEM_CHANNEL,ccci_ret);
    ASSERT(CCCI_SUCCESS == ccci_ret);

    ccci_sys_msg_trace(CCCI_SYS_MSG_INFO, CCCI_SYS_MSG_MOD_NORM, CCCI_SYS_MSG_INIT);
    
  #if defined(__SMART_PHONE_MODEM__) && defined(__HIF_CCIF_SUPPORT__) //router only
    //register callback function for MD sleep control: CPE will send this message
    ccci_register_sysmsgsvc_callback(CCMSG_ID_SYSMSGSVC_MD_SLEEP_CONTROL, ccci_md_sleep_control);
  #endif
  
    return;
 }

 
