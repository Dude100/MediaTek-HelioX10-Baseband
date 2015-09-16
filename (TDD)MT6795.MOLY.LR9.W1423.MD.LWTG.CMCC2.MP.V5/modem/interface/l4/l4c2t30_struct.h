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

/*******************************************************************************
 * Filename:
 * ---------
 *	l4c2t30_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for structure definition between T30 and L4C.
 *
 * Author:
 * -------
 *
 *=============================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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



#ifndef _L4C2T30_STRUCT_H
#define _L4C2T30_STRUCT_H

#include "kal_general_types.h"

typedef struct
{
	kal_bool	is_present;	/* is the parameter available */
	kal_uint8	para_value;	/* the parameter value */
	
}t30_sub_para_struct;


/* the structure defines the t30 session parameters. only valid in Class2. */
typedef struct
{
	t30_sub_para_struct	DF;
	t30_sub_para_struct	VR;
	t30_sub_para_struct	WD;
	t30_sub_para_struct	LN;
	
}t30_fdt_subparam_struct;



typedef struct
{
	t30_sub_para_struct	vrc;	/* vertical resolution conversion */
	t30_sub_para_struct	dfc;	/* data format conversion */
	t30_sub_para_struct	lnc;	/* page length conversion */
	t30_sub_para_struct	wdc;	/* page width conversion  */
	
}format_conv_struct;


typedef struct
{
	t30_sub_para_struct	pgl;	/* percentage of good line */
	t30_sub_para_struct	cbl;	/* max tolerable number of consecutive bad lines */
	
}recv_quality_thresd_struct;


typedef struct
{
	t30_sub_para_struct	sub;	/* SUB enable */
	t30_sub_para_struct	sep;	/* SEP enable */
	t30_sub_para_struct	pwd;	/* PWD enable */
	
}add_poll_cap_struct;


typedef struct
{
	kal_uint8	time;	/* timeout time value */
	kal_uint8	action;	/* action value */
	
}dte_inactive_struct;


typedef struct
{
	t30_sub_para_struct	rq;	/* receive copy quality enable */
	t30_sub_para_struct	tq;	/* transmit copy quality enable */
	
}copy_quality_struct;


typedef struct
{
	t30_sub_para_struct	rpr;	/* receiver parameters report */
	t30_sub_para_struct	tpr;	/* transmitter paramerters report */
	t30_sub_para_struct	idr;	/* ID string report */
	t30_sub_para_struct	nsr;	/* non-standard frames report */
	
}cap_report_struct;


typedef struct
{
	t30_sub_para_struct	VR;
	t30_sub_para_struct	BR;
	t30_sub_para_struct	WD;
	t30_sub_para_struct	LN;
	t30_sub_para_struct	DF;
	t30_sub_para_struct	EC;
	t30_sub_para_struct	BF;
	t30_sub_para_struct	ST;
   t30_sub_para_struct JP;
	
}t30_session_subparam_struct;


typedef struct
{
	kal_uint8	string[20]; 	/* local station ID string */
	kal_uint8	nsf_string[90];	/* pass-through non-standard octet string */
}t30_str_param_struct;


typedef struct
{
	t30_session_subparam_struct  session_param ; /* session subparameter*/
	kal_uint8	enable_polled;  				/* indecate document available for remotes's pooling*/
	kal_uint8	enable_polling; 
	cap_report_struct  report_param ;	/* negotiation reporting enable */
	kal_uint8	PI_enable ;  				/* procedure interrupt enable*/
	kal_uint8	page_status; 				/* page transfer status */
	copy_quality_struct	copy_quality;	
	dte_inactive_struct	inactivity_timer;	/*DTE inactivity timer*/
	kal_uint8	packet_protocol;	/* Packet protocol control */
	kal_uint8	data_bit_order;	/* Phace C data bit order */
	kal_uint8	EOL_align;	/* phace C received EOL alignment */
	kal_uint8	cap_to_receive; /* capability to receive */
	kal_uint8	HDLC_report;	/* HDLC frame reporting enable */
	add_poll_cap_struct	add_poll_cap;	/*address and polling capability */
	recv_quality_thresd_struct recv_quality_thresd; /* recive quality threshold */
	kal_uint8	phase_C_timeout;	
	kal_uint8	hangup_status;	
	kal_uint8	min_speed;		/* minimum phace C speed */
	kal_uint8	carrier_loss_to;	/* carrier loss timeout (class 1 ) */
	kal_uint8	esc_replace_enable;		/*double escape charactor replacement (class 1) */
	format_conv_struct	data_format_conver;		/* image data format conversion */
	kal_uint8	buffer_size[2];	/* buffer size, read only*/
	kal_uint8	CTC_retry_val;	/* CTC retry value */
	kal_uint8	NSF_msg_ind;	/* NSF message data indication */
	kal_uint8	FET_post_cmd;	/* end page or document command (only for class 2) */
		
}t30_rw_param_struct;


/* this struct is used for construct the local_param of MSG_ID_L4C_T30_TX_MSG_REQ */
typedef struct 
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 	mod_value;	/* modulation codes */
   t30_fdt_subparam_struct  fdt_subparam;	/*session parameters */
   	
}l4c_t30_tx_msg_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 	mod_value;	/* modulation codes */
}l4c_t30_rx_msg_req_struct;

/* this struct is used for construct the local_param of MSG_ID_L4C_T30_RW_PARAM_REQ */
typedef struct 
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 	action;
   kal_uint8 	serv_class;
   kal_uint32	 rw_param;
   t30_rw_param_struct 	t30_rw_param;
   	
}l4c_t30_rw_param_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8	action;
   kal_uint8 	serv_class;
	kal_uint32	rw_str_param;
	t30_str_param_struct	t30_str_param;
}l4c_t30_rw_str_param_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8 silence_time;
}l4c_t30_tx_silence_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8 silence_time;
}l4c_t30_rx_silence_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 mod_value;
}l4c_t30_tx_bcs_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 mod_value;
}l4c_t30_rx_bcs_req_struct;




typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8  result_code;
}l4c_t30_tx_msg_cnf_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8  result_code;
}l4c_t30_rx_msg_cnf_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8  result_code;
}l4c_t30_tx_bcs_cnf_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8  result_code;
}l4c_t30_rx_bcs_cnf_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8 	action;
	kal_bool		result_code;
	kal_uint8	result_str[80]; 
	
}l4c_t30_rw_param_cnf_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8	action;
	kal_bool		result_code;
	kal_uint8	result_str[110];
}l4c_t30_rw_str_param_cnf_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8  result_code;
}l4c_t30_ready_ind_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8	result_str[250];
}l4c_t30_report_param_ind_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8  page_status;
}l4c_t30_tx_ppm_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8  result_code;
}l4c_t30_tx_ppm_cnf_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  port;
}l4c_t30_transfer_uart_req_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  port;
    kal_uint8  is_esc_on;
}l4c_t30_transfer_uart_ind_struct;

#endif


