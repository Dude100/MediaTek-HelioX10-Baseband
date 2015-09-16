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
 * RMMI_MSGBASED_AT.C
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file is intended to handle the message based AT APIs
 *
 * Author:
 * -------
 * -------
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *****************************************************************************/
//mtk02514_zte

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_api.h"
#include "sysconf_statistics.h"
#include "task_config.h"
#include "kal_trace.h"
#include "ps_public_l4_msgid.h"
#include "tst_sap.h"

#if defined(__MESSAGE_BASED_AT_SUPPORT__) 

#include "rmmi_common_enum.h"
#include "l4c_common_enum.h"

#include "rmmi_msghdlr.h"
#include "rmmi_utility.h"
#include "rmmi_struct.h"
#include "tst_msgid.h"

#include "rmmi_msgbased_at.h"

#define TP_PS_NDEBUG 1

#if TP_PS_NDEBUG
#define kal_prompt_trace(...)
#endif

// ATCI messge based AT command relative definition
#define RMMI_MSG_BASED_CUSTOM_AT_CHANNEL   20   // This value could not exceed 20
#define RMMI_MSG_BASED_URC_CHANNEL     0
#define RMMI_MSG_BASED_PORT_BEGIN   100
#define RMMI_MSG_BASED_REQUEST_MODULE   MOD_MMI
#define RMMI_MSG_BASED_HANDLER_MODULE   MOD_ATCI
#define RMMI_MSG_BASED_CHANNEL_OFFSET   10

#define RMMI_MSGBASED_CR  0x0d
#define RMMI_MSGBASED_LF  0x0a
#define RMMI_MSGBASED_ESC  0x1b
#define RMMI_MSGBASED_CTRLZ  0x1a

typedef enum
{
    RMMI_MSGBASED_RESPONSE,
    RMMI_MSGBASED_URC
} rmmi_msgbased_ind_type;


kal_uint8 rmmi_msgbased_port[RMMI_MSG_BASED_CUSTOM_AT_CHANNEL];
kal_uint8 rmmi_msgbased_src[RMMI_MSG_BASED_CUSTOM_AT_CHANNEL];

/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_send_ilm
 * DESCRIPTION
 *  This function is used to send ILM to dest_id using the msg_id with data local_param_ptr and peer_buf_ptr
 *
 * PARAMETERS
 *  dest_id             [IN]
 *  msg_id              [IN]
 *  local_param_ptr  [IN]
 *  peer_buf_ptr        [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void rmmi_msgbased_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    module_type module = stack_get_active_module_id();
    

    msg_send6(module, dest_id, ATCI_SAP, (msg_type)msg_id, (local_para_struct *) local_param_ptr, (peer_buff_struct*) peer_buf_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_write_data
 * DESCRIPTION
 *  This function is used to send AT data back to the task who register channels
 *
 * PARAMETERS
 *  buffer             [IN]         output data
 *  length             [IN]         the length of output data
 *  stuff               [IN]        if we need to add <CR><LF> to the header and tailer or not
 *  src_id              [IN]        the output source ID
 *  type                [IN]        output is URC or response
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void rmmi_msgbased_write_data(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff, kal_uint8 src_id, rmmi_msgbased_ind_type type)
{
    kal_uint16 pdu_len, tmp_len;
    peer_buff_struct *peer_ptr;
    kal_uint8 *data, offset, port;
    rmmi_response_at_ind_struct *resposne_ptr;
    rmmi_urc_at_ind_struct *urc_ptr;
    void *local_ptr;
    msg_type msg;

    peer_ptr = (peer_buff_struct*) construct_peer_buff(length+5, 0, 0, TD_RESET); // +5: <CR>*2,<LF>*2,'\0'*1
    data = (kal_uint8 *)get_peer_buff_pdu(peer_ptr, &pdu_len);
    port = rmmi_msgbased_cid_2_port(rmmi_msgbased_srcid_2_cid(src_id));

    tmp_len = length;
    if (stuff == KAL_TRUE)
    {
        offset = 2;
        data[0] = RMMI_MSGBASED_CR;
        data[1] = RMMI_MSGBASED_LF;
        data[length+offset] = RMMI_MSGBASED_CR;
        data[length+offset+1] = RMMI_MSGBASED_LF;
        data[length+offset+2] = '\0';

        length += 4;
    }
    else
    {
        offset = 0;
        data[length] = '\0';
    }
    kal_mem_cpy(data+offset, buffer, tmp_len);

    if (type == RMMI_MSGBASED_RESPONSE)
    {
        resposne_ptr = (rmmi_response_at_ind_struct*)
                construct_local_para((kal_uint16) sizeof(rmmi_response_at_ind_struct), TD_RESET);
        resposne_ptr->length = length;
        resposne_ptr->port_id = port;

        local_ptr = resposne_ptr;
        msg = MSG_ID_RMMI_RESPONSE_AT_IND;
    }
    else
    {
        urc_ptr = (rmmi_urc_at_ind_struct*)
                construct_local_para((kal_uint16) sizeof(rmmi_urc_at_ind_struct), TD_RESET);
        urc_ptr->length = length;

        local_ptr = urc_ptr;
        msg = MSG_ID_RMMI_URC_AT_IND;
    }

    rmmi_msgbased_send_ilm(
            RMMI_MSG_BASED_REQUEST_MODULE, 
            msg, local_ptr, peer_ptr);
    
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_write_urc
 * DESCRIPTION
 *  This function is used to send AT URC back to the task who register channels
 *
 * PARAMETERS
 *  buffer             [IN]         output data
 *  length             [IN]         the length of output data
 *  stuff               [IN]        if we need to add <CR><LF> to the header and tailer or not
 *
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_msgbased_write_urc(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff)
{
    rmmi_msgbased_write_data(buffer, length, stuff, 0xff, RMMI_MSGBASED_URC);
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_write_response
 * DESCRIPTION
 *  This function is used to send AT response back to the task who register channels
 *
 * PARAMETERS
 *  buffer             [IN]         output data
 *  length             [IN]         the length of output data
 *  stuff               [IN]        if we need to add <CR><LF> to the header and tailer or not
 *  src_id              [IN]        the output source ID
 *
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_msgbased_write_response(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff, kal_uint8 src_id)
{
    rmmi_msgbased_write_data(buffer, length, stuff, src_id, RMMI_MSGBASED_RESPONSE);
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_cid_2_srcid
 * DESCRIPTION
 *  This function is used to transfer from channel ID to source ID by table lookup
 *  The source ID begins from RMMI_MSG_AT_SRC
 *  If we could not find the source ID, we will return INVALID_SRC
 * PARAMETERS
 *  cid     [IN]        
 * RETURNS
 *  source ID
 *****************************************************************************/
kal_uint8 rmmi_msgbased_cid_2_srcid(kal_uint8 cid)
{
    cid -= RMMI_MSG_BASED_CHANNEL_OFFSET;
    if (cid >= RMMI_MSG_BASED_CUSTOM_AT_CHANNEL)
        return INVALID_SRC;
    else
        return rmmi_msgbased_src[cid];
}


/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_srcid_2_cid
 * DESCRIPTION
 * This function is used to transfer source id to channel id
 * The channel ID is begin from RMMI_MSG_BASED_CHANNEL_OFFSET
 * If we could not find the channel ID, we will return 0xff
 * PARAMETERS
 *  src_id      [IN]        
 * RETURNS
 *  channel ID
 *****************************************************************************/
kal_uint8 rmmi_msgbased_srcid_2_cid(kal_uint8 src_id)
{
    kal_uint8 cid;

    for (cid = 0; cid < RMMI_MSG_BASED_CUSTOM_AT_CHANNEL; cid++)
    {
        if (rmmi_msgbased_src[cid] == src_id)
        {
            return cid+RMMI_MSG_BASED_CHANNEL_OFFSET;
        }
    }
    return 0xff;
    
}


/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_cid_2_port
 * DESCRIPTION
 *  This function is used to transfer from channel ID to port ID by table lookup
 *  The port ID begins from RMMI_MSG_BASED_PORT_BEGIN
 *  If we could not find the port ID, we will return uart_port_null
 * PARAMETERS
 *  cid     [IN]        
 * RETURNS
 *  port ID
 *****************************************************************************/
kal_uint8 rmmi_msgbased_cid_2_port(kal_uint8 cid)
{
    cid-=RMMI_MSG_BASED_CHANNEL_OFFSET;
    if (cid >= RMMI_MSG_BASED_CUSTOM_AT_CHANNEL)
        return uart_port_null;
    else
        return rmmi_msgbased_port[cid];
}


/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_port_2_cid
 * DESCRIPTION
 *   This function is used to transfer port id to channel id
 *   The channel ID is begin from RMMI_MSG_BASED_CHANNEL_OFFSET
 *   If we could not find the channel ID, we will return 0xff
 * PARAMETERS
 *  port        [IN]        
 * RETURNS
 *  channel ID
 *****************************************************************************/
kal_uint8 rmmi_msgbased_port_2_cid(kal_uint8 port)
{
    kal_uint8 cid;

    for (cid = 0; cid < RMMI_MSG_BASED_CUSTOM_AT_CHANNEL; cid++)
    {
        if (rmmi_msgbased_port[cid] == port)
        {
            return cid+RMMI_MSG_BASED_CHANNEL_OFFSET;
        }
    }
    return 0xff;
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_is_valid_src
 * DESCRIPTION
 *   This function is used to judge if the input src_id is a valid ID for "message based AT ocmmand" or not
 * PARAMETERS
 *  src_id        [IN]        
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool rmmi_msgbased_is_valid_src(kal_uint8 src_id)
{
    kal_uint8 cid;

    cid = rmmi_msgbased_srcid_2_cid(src_id);
    return cid == 0xff ? KAL_FALSE : KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  rmmi_msgbased_register_channel
 * DESCRIPTION
 *   This function is used to init source/port mapping accroding the ch_num
 * PARAMETERS
 *  ch_num        [IN]        
 * RETURNS
 *  RMMI_MSG_BASED_PORT_BEGIN
 *****************************************************************************/
kal_uint8 rmmi_msgbased_register_channel(kal_uint8 ch_num)
{
    kal_uint8 i, src;
    
    src = RMMI_MSG_AT_SRC;
    for (i=0; i<ch_num; i++)
    {
        kal_prompt_trace(
            stack_get_active_module_id(), 
            "[Reg] Register channel(%d): source: %d, port: %d",
            i, src, RMMI_MSG_BASED_PORT_BEGIN+i);

        rmmi_msgbased_port[i] = RMMI_MSG_BASED_PORT_BEGIN + i;
        rmmi_msgbased_src[i] = src++;
    }

    return RMMI_MSG_BASED_PORT_BEGIN;
}

/*****************
* The following is for ZTE
******************/

#define MAX_TP_QUEUE_LENGTH     2048
#define MAX_TP_URC_BUFFER_LENGTH    2048

typedef kal_int32 (*PS_CALLBACK) (kal_uint8  channelId, kal_char *buf, kal_uint16 iDataLen, kal_uint8  iFlag);

typedef struct
{
    kal_uint16 length;
    kal_char data[MAX_TP_QUEUE_LENGTH];
    kal_bool is_sms_cmd;
} tp_queue_struct;

typedef enum
{
    TP_ERROR = -1,
    TP_SUCCESS
} tp_result;

/* If you want to modify the number of channels,
    Please modify the constant RMMI_MSG_BASED_CUSTOM_AT_CHANNEL
    But our modem could only support max 20 channels
*/
tp_queue_struct tp_buffer[RMMI_MSG_BASED_CUSTOM_AT_CHANNEL];

PS_CALLBACK tp_callback = NULL;

kal_int32 tp_port_begin = -1;
kal_int8 tp_channelNum = 0;

kal_char tp_urc_buffer[MAX_TP_URC_BUFFER_LENGTH];
kal_uint16 tp_urc_buffer_len = 0;

/*****************************************************************************
 * FUNCTION
 *  tp_ps_start
 * DESCRIPTION
 *  This function is used to start message based AT command mechanism by customer
 *
 * PARAMETERS
 *  buffer             [IN]         output data
 *
 * RETURNS
 *  TP_SUCCESS or TP_ERROR
 *****************************************************************************/
kal_int32 tp_ps_start(kal_int8 channelNum) 
{
    kal_uint8 i;
    rmmi_register_channel_req_struct *req_ptr;
    
    if(channelNum > RMMI_MSG_BASED_CUSTOM_AT_CHANNEL)
    {
        kal_prompt_trace(
            stack_get_active_module_id(), 
            "[Start] Register channel number(%d) is larger than the maximum supported number: %d",
            channelNum, RMMI_MSG_BASED_CUSTOM_AT_CHANNEL);
        return TP_ERROR;
    }
    else if (tp_channelNum != 0)
    {
        kal_prompt_trace(
            stack_get_active_module_id(), 
            "[Start] We have already been started");
        return TP_ERROR;
    }

    tp_channelNum = channelNum;

    //init buffers
    for(i=0; i<channelNum; i++)
    {
        tp_buffer[i].length = 0;
        tp_buffer[i].data[0] = '\0';
        tp_buffer[i].is_sms_cmd = KAL_FALSE;
    }

    //send MSG_ID_ATCI_REGISTER_CHANNEL_REQ
    req_ptr =  (rmmi_register_channel_req_struct*)
            construct_local_para((kal_uint16) sizeof(rmmi_register_channel_req_struct), TD_RESET);

    req_ptr->ch_num = channelNum;

    rmmi_msgbased_send_ilm(
            RMMI_MSG_BASED_HANDLER_MODULE, 
            MSG_ID_RMMI_REGISTER_CHANNEL_REQ, 
            req_ptr, NULL);

    return TP_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  tp_ps_reg_callback
 * DESCRIPTION
 *  This function is used to callback function which is used to send AT data back to register
 *
 * PARAMETERS
 *  callback_func             [IN]         
 *
 * RETURNS
 *  TP_SUCCESS or TP_ERROR
 *****************************************************************************/
kal_int32 tp_ps_reg_callback(PS_CALLBACK callback_func)
{
    tp_callback = callback_func;

    if ( !(tp_callback == NULL || tp_port_begin == -1))
    {
        if (tp_urc_buffer_len > 0)
        {
            tp_callback(
                    RMMI_MSG_BASED_URC_CHANNEL, 
                    tp_urc_buffer, 
                    tp_urc_buffer_len, 1);
        }
    }

    return TP_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  tp_ps_Send
 * DESCRIPTION
 *  This function is used to send AT command to MOD_ATCI
 *  Return success means that the command is sent, not the command is executed successfully
 * PARAMETERS
 *  iFlag             [IN]              always be 1
 *  channelId             [IN]       
 *  pDataPtr             [IN]          
 *  iDataLen             [IN]          
 *
 * RETURNS
 *  TP_SUCCESS or TP_ERROR
 *****************************************************************************/
kal_int32 tp_ps_Send(kal_uint8 iFlag, kal_uint8  channelId, kal_uint8 *pDataPtr, kal_uint16 iDataLen) 
{
    kal_uint16 i;
    kal_int32 result = TP_ERROR;
    module_type type;
    tp_queue_struct *buffer;
    rmmi_exe_at_req_struct *req_ptr;
    peer_buff_struct *peer_ptr;
    kal_uint8 *data_ptr;
    kal_uint8 cmd_string[10];
    kal_char input_hint_string[] = "\r\n> ";

    type = stack_get_active_module_id();
    if (iFlag != 1)
    {
        kal_prompt_trace(
                type,
                "[Send] Warning: iFlag shoulbe be 1: %d", iFlag);
    }

    if (tp_port_begin == -1)
    {
        kal_prompt_trace(
                type,
                "[Send] ERROR: havn't start PS, please call tp_ps_start first");
    }
    else if(pDataPtr == NULL)
    {
        kal_prompt_trace(
                type,
                "[Send] ERROR: input data pointer is NULL!!!");
    }        
    else if (tp_callback == NULL)
    {
        kal_prompt_trace(
                type,
                "[Send] ERROR: havn't register TP callback function");
    }
    else if(channelId >= tp_channelNum)
    {
        kal_prompt_trace(
                type,
                "[Send] ERROR: invalid channelID: ch:%d, max:%d ", channelId, tp_channelNum);
    }
    else
    {
        buffer = &tp_buffer[channelId];

        if ( (buffer->length + iDataLen) > MAX_TP_QUEUE_LENGTH)
        {
            kal_prompt_trace(
                    type,
                    "[Send] ERROR: buffer[%d] is full, clean the buffer!!! Org:%d, New:%d, Max: %d", 
                    channelId, buffer->length, iDataLen, 
                    MAX_TP_QUEUE_LENGTH);
            buffer->length = 0;
            buffer->is_sms_cmd = KAL_FALSE;
        }
        else
        {
            result = TP_SUCCESS;
            
            //Put the data into the buffer
            kal_mem_cpy(buffer->data+buffer->length, pDataPtr, iDataLen);

            //Update buffer length
            buffer->length += iDataLen;

            //check if the data is a complete command according to the <CR><LF>
            for(i=0; i<buffer->length;i++)
            {
                if (buffer->is_sms_cmd == KAL_FALSE &&
                    (buffer->data[i] == RMMI_MSGBASED_CR || buffer->data[i] == RMMI_MSGBASED_LF) )
                {
                    kal_mem_cpy(cmd_string, buffer->data, 10);
                    toUpper(cmd_string);
                    if (is_sms_command(cmd_string, 10) == KAL_TRUE)
                    {
                        buffer->is_sms_cmd = KAL_TRUE;

                        // send hint string
                        tp_callback(channelId, input_hint_string, strlen(input_hint_string), 1);
                        buffer->data[i] = RMMI_MSGBASED_LF;

                        kal_prompt_trace(
                            type,
                            "[Send] INFO: Enter SMS input mode");
                    }
                    break;
                }
                else if (buffer->is_sms_cmd == KAL_TRUE &&
                    (buffer->data[i] == RMMI_MSGBASED_CTRLZ || buffer->data[i] == RMMI_MSGBASED_ESC) )
                {
                    kal_prompt_trace(
                            type,
                            "[Send] INFO: Leave SMS input mode");

                    buffer->is_sms_cmd = KAL_FALSE;

                    if (buffer->data[i] == RMMI_MSGBASED_ESC)
                    {
                        tp_callback(channelId, "\r\nOK\r\n", 6, 1);
                        //clean the buffer
                        buffer->length = 0;
                        return;
                    }
                    break;
                }
            }

            
            if (i != buffer->length)
            {
                if (buffer->is_sms_cmd == KAL_TRUE)
                {
                    kal_prompt_trace(
                        type,
                        "[Send] INFO: in SMS input mode, length: %d", 
                        buffer->length);
                }
                else
                {
                    // send the command
                    req_ptr = (rmmi_exe_at_req_struct*)
                            construct_local_para((kal_uint16) sizeof(rmmi_exe_at_req_struct), TD_RESET);
                    peer_ptr = (peer_buff_struct*) construct_peer_buff(buffer->length, 0, 0, TD_RESET);
                    data_ptr= (kal_uint8 *)get_peer_buff_pdu(peer_ptr, &i);

                    req_ptr->length = buffer->length;
                    req_ptr->port_id = channelId + tp_port_begin;

                    kal_mem_cpy(data_ptr, buffer->data, buffer->length);

                    rmmi_msgbased_send_ilm(
                            RMMI_MSG_BASED_HANDLER_MODULE, 
                            MSG_ID_RMMI_EXE_AT_REQ,
                            req_ptr, peer_ptr);

                    //clean the buffer
                    buffer->length = 0;
                }
            }
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  tp_ps_test_callback
 * DESCRIPTION
 *  This function is the test purpose callback function for testing
 *
 * PARAMETERS
 *  channelId             [IN]              always be 1
 *  buf             [IN]       
 *  iDataLen             [IN]          
 *  iFlag             [IN]          
 *
 * RETURNS
 *  TP_SUCCESS or TP_ERROR
 *****************************************************************************/
static kal_int32 tp_ps_test_callback(kal_uint8  channelId, kal_char *buf, kal_uint16 iDataLen, kal_uint8  iFlag)
{
    /*This function is used to test the tp ps functions*/
    module_type type;

    type = stack_get_active_module_id();
    
    kal_prompt_trace(
            type, 
            "[Callback] Ch: %d, length: %d, flag: %d, buf:%s", 
            channelId, iDataLen, iFlag, buf);

    return 0;
}

/******************************************
* the following is used to handle the primitives from ATCI *
*******************************************/
/*****************************************************************************
 * FUNCTION
 *  tp_ps_register_channel_cnf_hdlr
 * DESCRIPTION
 *  This function is used to handle the message MSG_ID_RMMI_REGISTER_CHANNEL_CNF
 *
 * PARAMETERS
 *  local_para_ptr             [IN]              
 *  peer_buff_ptr             [IN]       
 *
 * RETURNS
 * void
 *****************************************************************************/
static void tp_ps_register_channel_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    rmmi_register_channel_cnf_struct *cnf_ptr;

    cnf_ptr = (rmmi_register_channel_cnf_struct*) local_para_ptr;
    tp_port_begin = cnf_ptr->begin_port_id;
    
    kal_prompt_trace(
            stack_get_active_module_id(),
            "[Hdlr] Receive register channel confirm, result:%d, begin_port:%d", 
            cnf_ptr->result, tp_port_begin);

    if ( !(tp_callback == NULL || tp_port_begin == -1))
    {
        if (tp_urc_buffer_len > 0)
        {
            tp_callback(
                    RMMI_MSG_BASED_URC_CHANNEL, 
                    tp_urc_buffer, 
                    tp_urc_buffer_len, 1);
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  tp_ps_exe_at_cnf_hdlr
 * DESCRIPTION
 *  This function is used to handle the message MSG_ID_RMMI_EXE_AT_CNF
 *
 * PARAMETERS
 *  local_para_ptr             [IN]              
 *  peer_buff_ptr             [IN]       
 *
 * RETURNS
 * void
 *****************************************************************************/
static void tp_ps_exe_at_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    rmmi_exe_at_cnf_struct *cnf_ptr;
    
    cnf_ptr = (rmmi_exe_at_cnf_struct*) local_para_ptr;
    
    kal_prompt_trace(
            stack_get_active_module_id(),
            "[Hdlr] ATCI has received the request, result:%d, from port:%d", 
            cnf_ptr->result, cnf_ptr->port_id);
}

/*****************************************************************************
 * FUNCTION
 *  tp_ps_handling_at_indication
 * DESCRIPTION
 *  This function is used to handle the response/URC data from MOD_ATCI
 *
 * PARAMETERS
 *  channelId             [IN]              
 *  buf             [IN]       
 *  iDataLen        [IN]       
 *
 * RETURNS
 * void
 *****************************************************************************/
static void tp_ps_handling_at_indication(kal_uint8  channelId, kal_char *buf, kal_uint16 iDataLen)
{
    kal_char *data;
    
    if (tp_callback == NULL || tp_port_begin == -1)
    {
        if (tp_callback == NULL)
        {
            kal_prompt_trace(
                    stack_get_active_module_id(),
                    "[Hdlr] ERROR: havn't register TP callback function");
        }
        else if (tp_port_begin == -1)
        {
            kal_prompt_trace(
                    stack_get_active_module_id(),
                    "[Hdlr] ERROR: havn't start PS, please call tp_ps_start first");
        }

        // buffer the URC
        if (channelId == RMMI_MSG_BASED_URC_CHANNEL)
        {
            kal_prompt_trace(
                    stack_get_active_module_id(),
                    "[Hdlr] Buffer the URC: %s", buf);
            if ( (tp_urc_buffer_len + iDataLen) > MAX_TP_URC_BUFFER_LENGTH)
            {
                kal_prompt_trace(
                    stack_get_active_module_id(),
                    "[Hdlr] URC buffer is full, clean the buffer", buf);

                tp_urc_buffer_len = 0;
            }
            
            if (iDataLen > MAX_TP_URC_BUFFER_LENGTH)
            {
               kal_prompt_trace(
                    stack_get_active_module_id(),
                    "[Hdlr] ERROR: the URC is too large, please increase the URC buffer");
            }
            else
            {
                kal_mem_cpy(tp_urc_buffer+tp_urc_buffer_len, buf, iDataLen);
                tp_urc_buffer_len += iDataLen;
            }
        }
    }
    else
    {

        data = get_ctrl_buffer(iDataLen);
        kal_mem_cpy(data, buf, iDataLen);
        
        tp_callback(channelId, data, iDataLen, 1);
        
        free_ctrl_buffer(data);
    }

}

/*****************************************************************************
 * FUNCTION
 *  tp_ps_response_at_ind_hdlr
 * DESCRIPTION
 *  This function is used to handle the message MSG_ID_RMMI_RESPONSE_AT_IND
 *
 * PARAMETERS
 *  local_para_ptr             [IN]              
 *  peer_buff_ptr             [IN]       
 *
 * RETURNS
 * void
 *****************************************************************************/
static void tp_ps_response_at_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    rmmi_response_at_ind_struct *cnf_ptr;
    kal_uint16 data_length;
    kal_char *pdu_ptr;
    
    cnf_ptr = (rmmi_response_at_ind_struct*) local_para_ptr;
    pdu_ptr = (kal_char*) get_peer_buff_pdu(peer_buff_ptr, &data_length);

    tp_ps_handling_at_indication(
        cnf_ptr->port_id - tp_port_begin, 
        pdu_ptr, 
        cnf_ptr->length);
}

/*****************************************************************************
 * FUNCTION
 *  tp_ps_urc_at_ind_hdlr
 * DESCRIPTION
 *  This function is used to handle the message MSG_ID_RMMI_URC_AT_IND
 *
 * PARAMETERS
 *  local_para_ptr             [IN]              
 *  peer_buff_ptr             [IN]       
 *
 * RETURNS
 * void
 *****************************************************************************/
static void tp_ps_urc_at_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    rmmi_urc_at_ind_struct *cnf_ptr;
    kal_uint16 data_length;
    kal_char *pdu_ptr;
    
    cnf_ptr = (rmmi_urc_at_ind_struct*) local_para_ptr;
    pdu_ptr = (kal_char*) get_peer_buff_pdu(peer_buff_ptr, &data_length);

    tp_ps_handling_at_indication(
        RMMI_MSG_BASED_URC_CHANNEL, 
        pdu_ptr, 
        cnf_ptr->length);
}


/*****************************************************************************
 * FUNCTION
 *  tp_ps_urc_at_ind_hdlr
 * DESCRIPTION
 *  This function is used to handle the message relative to message based AT command mechanism
 *
 * PARAMETERS
 *  ilm_ptr             [IN]              
 *
 * RETURNS
 * void
 *****************************************************************************/
void tp_ps_message_handler(ilm_struct *ilm_ptr)
{
    kal_prompt_trace(MOD_ATCI, "Enter TP Handler");
    if (ilm_ptr->msg_id == MSG_ID_RMMI_REGISTER_CHANNEL_CNF)
    {
        tp_ps_register_channel_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_RMMI_EXE_AT_CNF)
    {
        tp_ps_exe_at_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_RMMI_RESPONSE_AT_IND)
    {
        tp_ps_response_at_ind_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_RMMI_URC_AT_IND)
    {
        tp_ps_urc_at_ind_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
    #ifdef TP_PS_NDEBUG

    else if (ilm_ptr->msg_id == MSG_ID_TST_INJECT_STRING)
    {
        kal_int8 num;
        tst_module_string_inject_struct *msg_ptr;
        msg_ptr = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;


        switch(msg_ptr->index)
        {
            case 0: //reg_callback
                tp_ps_reg_callback(tp_ps_test_callback);
                break;
            case 1: //start
                num = atoi((kal_char *)msg_ptr->string);
                kal_prompt_trace(stack_get_active_module_id(), "NUM: %d", num);
                tp_ps_start(num);
                break;
            case 2: // send
                tp_ps_Send(1, 0, msg_ptr->string, strlen((kal_char*)msg_ptr->string));
                break;
            case 3: // send <CR>
                tp_ps_Send(1, 0, "\r", 1);
                break;
            case 4: // send <CTRL+Z>
                num = RMMI_MSGBASED_CTRLZ;
                tp_ps_Send(1, 0, (kal_uint8*) &num, 1);
                break;
            case 5: // send <ESC>
                num = RMMI_MSGBASED_ESC;
                tp_ps_Send(1, 0, (kal_uint8*) &num, 1);
                break;
            case 6: // send with invalid iFlag
                tp_ps_Send(0, 0, msg_ptr->string, strlen((kal_char*)msg_ptr->string));
                break;
            case 7: // send with invalid channel
                tp_ps_Send(1, 25, msg_ptr->string, strlen((kal_char*)msg_ptr->string));
                break;
            case 8: // send with invalid pointer
                tp_ps_Send(1, 0, NULL, strlen((kal_char*)msg_ptr->string));
                break;
            case 9: // send to max channel
                tp_ps_Send(1, RMMI_MSG_BASED_CUSTOM_AT_CHANNEL-1, msg_ptr->string, strlen((kal_char*)msg_ptr->string));
                break;
            case 10: // send <CR>
                tp_ps_Send(1, RMMI_MSG_BASED_CUSTOM_AT_CHANNEL-1, "\r", 1);
                break;
            case 11: // send <CTRL+Z>
                num = RMMI_MSGBASED_CTRLZ;
                tp_ps_Send(1, RMMI_MSG_BASED_CUSTOM_AT_CHANNEL-1, (kal_uint8*) &num, 1);
                break;
            case 12: // send <ESC>
                num = RMMI_MSGBASED_ESC;
                tp_ps_Send(1, RMMI_MSG_BASED_CUSTOM_AT_CHANNEL-1, (kal_uint8*) &num, 1);
                break;
            case 13: // send <ESC>
                tp_ps_Send(1, 0, msg_ptr->string, strlen((kal_char*)msg_ptr->string));
                tp_ps_Send(1, 0, "\r", 1);
                break;
            case 14: // send <ESC>
                tp_ps_Send(1, RMMI_MSG_BASED_CUSTOM_AT_CHANNEL-1, msg_ptr->string, strlen((kal_char*)msg_ptr->string));
                tp_ps_Send(1, RMMI_MSG_BASED_CUSTOM_AT_CHANNEL-1, "\r", 1);
                break;


            default:
                break;
        }
        
    }
    #endif

}

#endif

