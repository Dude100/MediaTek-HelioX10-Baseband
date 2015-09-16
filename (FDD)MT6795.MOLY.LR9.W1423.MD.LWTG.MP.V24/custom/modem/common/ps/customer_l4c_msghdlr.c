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
 * Customer_l4c_msghdlr.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for �K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
/*
#ifdef __MODEM_CARD__
#include "ps_public_l4_msgid.h"
#include "ps_public_struct.h"
#include "l4c_utility.h"
#include "l4c_nw_cmd.h"
#include "l4c_common_enum.h"
#endif
*/
void customer_l4c_msghdlr(ilm_struct* ilm_ptr);

void customer_l4c_msghdlr(ilm_struct* ilm_ptr)
{
    /*****************************************
    switch(ilm_ptr->msg_id){
        case MSG_ID_CUSTOM_MESSAGE:	
        
            // customer can handle their own message here
        
            custom_message_handler(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

        default:

            // if customer want to handle some undefined message
            // they can write the handler codes here
        
            custom_undefined_messages_handler();
            break;
    }
    #endif
    *****************************************/
/*
    switch(ilm_ptr->msg_id)
    {
    #ifdef __MODEM_CARD__
        case MSG_ID_L4C_USB_SUSPEND_REQ:
        {
            l4c_usb_suspend_req_struct *param_ptr = (l4c_usb_suspend_req_struct*)ilm_ptr->local_para_ptr;
            
            if (l4c_get_cfun_state() == 1)
            {
                if (param_ptr->remote_wakeup_enable == KAL_TRUE)
                {
                #if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
                    l4c_nw_set_fd_mode_req(L4C_SRC, 1);
                #endif
                }
                else
                {
                    l4c_nw_cfun_state_req(L4C_SRC, 4);
                }
            }
            break;
        }

        case MSG_ID_L4C_USB_RESUME_REQ:
        {
        #if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
            l4c_nw_set_fd_mode_req(L4C_SRC, 0);
        #endif
            
            if (l4c_get_cfun_state() == 4)
            {
                l4c_nw_cfun_state_req(L4C_SRC, 1);
            }

            break;
        }
    #endif
        default:
            break;
    }
*/
}


