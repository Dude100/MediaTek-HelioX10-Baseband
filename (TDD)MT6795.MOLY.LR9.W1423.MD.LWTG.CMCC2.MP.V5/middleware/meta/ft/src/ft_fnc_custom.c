/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_custom.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Misc Function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/*************************************************************************
 * Include Statements for KAL
 *************************************************************************/
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "md_mw_sap.h"
#include "svc_sap.h"
#include "ft_msgid.h"
#include "nvram_msgid.h"
#ifdef __MTK_TARGET__
#include <stdio.h>
#endif
/*************************************************************************
 * Include Statements for MAUI
 *************************************************************************/
#include "ftc_msg.h"
#include "ft_private.h"
// added in RHR first round
#include "kal_public_api.h"
#include "kal_general_types.h"
//MSBB remove #include "fctycomp_config.h"
// added in RHR first round
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
void FT_Custom_Operation(ilm_struct *ptrMsg)
{
    ilm_struct        ilm_ptr;
    kal_uint16        pdu_length;
    kal_uint8	       *pdu_ptr = NULL;
    kal_uint16	      pdu_length_new;
    kal_uint8	       *pdu_ptr_new;
    peer_buff_struct *peer_buff_new;
    FT_CUSTOMER_REQ  *p_req = (FT_CUSTOMER_REQ *)ptrMsg->local_para_ptr;
    if(ptrMsg->peer_buff_ptr == NULL)  // do nothing
        return; 
    switch(p_req->type)
    {
        case FT_CUSTOMER_OP_BASIC:
            {

                pdu_ptr = get_peer_buff_pdu( ptrMsg->peer_buff_ptr, &pdu_length );

                // construct a peer buffer to send to NVRAM
                if( NULL != (peer_buff_new=construct_peer_buff(pdu_length, 0, 0, TD_CTRL)) ) 
                {
                    pdu_ptr_new = get_peer_buff_pdu( peer_buff_new, &pdu_length_new );
                    kal_mem_cpy(pdu_ptr_new, pdu_ptr, pdu_length);
                    peer_buff_new->pdu_len = pdu_length;
                }
                FT_ALLOC_OTHER_MSG(&ilm_ptr, sizeof(ftc_basic_req_struct));
                ilm_ptr.peer_buff_ptr = peer_buff_new;
                FT_SEND_MSG(MOD_FT, MOD_FTC, FT_FTC_SAP , (msg_type)MSG_ID_FTC_BASIC_REQ, &ilm_ptr);
                peer_buff_new=NULL;/* make sure FTC will release the mem*/
                break;
            }
        default:
            break;
    } 
}
void FT_Handle_FTC_CNF(ilm_struct *ptrMsg)
{
    ilm_struct		ilm_ptr;
    FT_CUSTOMER_CNF  *ptrMsg2;  // send back to PC

    switch (ptrMsg->msg_id)
    {
        case MSG_ID_FTC_BASIC_CNF:
            {
                ftc_basic_cnf_struct *tmp_local_para = NULL;  // from FTC Task
                tmp_local_para = (ftc_basic_cnf_struct*)ptrMsg->local_para_ptr;

                FT_ALLOC_MSG(&ilm_ptr ,sizeof(FT_CUSTOMER_CNF));

                ilm_ptr.peer_buff_ptr = ptrMsg->peer_buff_ptr;
                ptrMsg2 = (FT_CUSTOMER_CNF*)ilm_ptr.local_para_ptr;  

                ptrMsg2->header.ft_msg_id = FT_CUSTOM_CNF_ID;
                ptrMsg2->type = FT_CUSTOMER_OP_BASIC; 
                ptrMsg2->status = tmp_local_para->status; //FTC_CNF_OK;
                // for debug   
                sprintf((kal_char *)g_FT_debug_buf, "recv message from ftc");
                tst_sys_trace(g_FT_debug_buf); 
            }
            break;
        default:
            return;

    }
    // send confirm to PC
    FT_SEND_MSG_TO_PC(&ilm_ptr);
}
