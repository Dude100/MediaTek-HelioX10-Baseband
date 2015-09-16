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
 * RMMI_GATI.H
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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

#ifdef __GATI_ENABLE__
#ifndef __RMMI_GATI_H__
#define __RMMI_GATI_H__

/* Constant */
#define  GATI_MAX_BUFFER_COUNT   20     /* The maximum data count where the data is sent
                                                                   from other modules which are not the module who active the binary mode */
#define  GATI_MAX_MODULE_COUNT   2      /* max modules which uses this interface */

/* Structure */
typedef struct
{
    module_type mod_id;         /* The module id which uses this interface. */
    kal_uint8 src_id;                /* The src_id which is used to transmit data by the module */
    kal_uint8 control_flag;       /* The control status of the module */
    kal_bool wait_rtw_ind;       /* If the module is waiting for the RTW indication */
} gati_mod_src_struct;

typedef struct gati_buffer_struct
{
    kal_uint8 length;                       /* The length of URC data in the URC buffer */
    kal_uint8 *buffer;                      /* buffer */
    kal_uint8 data_type;                 /* gati_output_data_type */
    module_type mod_id;                /* module id */
    kal_uint8 src_id;                       /* source id for non gati data */
    kal_bool stuff;                          /* staff for non gati data */
    struct gati_buffer_struct *next; /* next buffer node */
} gati_buffer_struct;

/* Message Structure */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 data[MAX_DATA_QUEUE_LENGTH];  /* data  */
    kal_uint16 size;                                        /* size of the input data */
    kal_uint16 buf_size;                                  /* avariable size of the output buffer */
} gati_data_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} gati_data_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 data[MAX_DATA_QUEUE_LENGTH];  /* data  */
    kal_uint16 size;                                        /* size of the input data */
    kal_uint8 data_type;                                /* gati_output_data_type_enum */
} gati_data_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 actual_write;    /* the actual written size of data which is written to the output buffer of ATCI */
} gati_data_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 buf_size;    /* avariable size of the output buffer */
} gati_rtw_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 control_flag; /* bit map to set flow controls using gati_flow_contorl_num */
} gati_ctrl_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;        /* If the control request is successful of not */
    kal_uint8 control_flag; /* Return the current status of each control mode bit to indicate if the control is active or inactive */
} gati_ctrl_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mode; /* Binary mode or command mode specify by the gati_mode_enum */
} gati_switch_mode_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;    /* If the switch request is successful of not */
    kal_uint8 mode;     /* Return the current mode of the src_id */
} gati_switch_mode_cnf_struct;

/* ENUM */
typedef enum
{
    GATI_FLOWCTRL_SUSPEND_READ_FROM_UART = 1,   /* active suspend read from UART flow control */
    GATI_FLOWCTRL_RTW = 2,                                      /* active RTW indication flow control */
    GATI_FLOWCTRL_WRITE_CONFRIM = 4                     /* active write confirm flow control */
} gati_flow_contorl_enum;

typedef enum
{
    GATI_OUTPUT_NORMAL,     /* The type of output data is normal type which might be partially put to the output buffer of the ATCI */
    GATI_OUTPUT_URC,            /* The type of output data is a URC. Note that this type of data is an integrity type implicitly. */
    GATI_OUTPUT_INTEGRITY,  /*    The type of output data need to be integrity which will not be put into the output buffer of the ATCI if the space of the buffer is not enough */
    GATI_NOT_GATI_DATA       /*    Data not sent from MOD_APP for internal use only */
} gati_output_data_type_enum;

typedef enum
{
    GATI_CMD_MODE,      /* Command Mode */
    GATI_BINARY_MODE    /* Binary Mode */
} gati_mode_enum;

/* Function Declare */
/* Messages handler functions */
extern void gati_data_req_hdlr(local_para_struct *local_para_ptr, module_type mod_id);
extern void gati_data_rsp_hdlr(module_type mod_id);
extern void gati_ctrl_req_hdlr(local_para_struct *local_para_ptr, module_type mod_id);
extern void gati_switch_mode_req_hdlr(local_para_struct *local_para_ptr, module_type mod_id);

/* GATI utility functions */
extern void gati_suspend_read_from_uart(module_type mod_id, kal_uint8 src_id);
extern void gati_register_module(module_type mod_id, kal_uint8 src_id);
extern void gati_flush_buffer(void);
extern kal_bool gati_insert_data_to_buffer(
                    kal_uint8 *data,
                    kal_uint16 size,
                    kal_uint8 src_id,
                    module_type mod_id,
                    kal_uint8 data_type,
                    kal_bool stuff);
extern kal_uint8 gati_search_mod_index(module_type mod_id);

/* Utility functions for users */
extern module_type gati_search_command(kal_uint8 *cmd_string);
extern kal_bool gati_command_hdlr(kal_uint8 *cmd_string, kal_uint8 *full_string);

/* Messages transmitting Relative functions */
extern void gati_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void gati_send_rtw_ind(kal_uint8 src_id, kal_uint16 buf_size);
extern void gati_send_data_ind(module_type mod_id, kal_uint8 *data_string, kal_uint16 data_size);
extern void gati_send_data_cnf(kal_uint8 index, kal_uint16 actual_write);
extern void gati_send_ctrl_cnf(module_type mod_id, kal_bool result, kal_uint8 control_flag);
extern void gati_send_switch_mode_cnf(module_type mod_id, kal_bool result, kal_uint8 mode);

#endif /* __RMMI_GATI_H__ */ 
#endif /* __GATI_ENABLE__ */ 

