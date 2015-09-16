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
 *   em_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Engineer mode related structures.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

 
#ifndef _EM_STRUCT_H
#define _EM_STRUCT_H

#include "ps_public_struct.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
/*Justin: RHR*/
//#include "rrm_context.h"
//#include "meas_context.h"
#include "em_public_struct.h"

#define MAX_NUM_CELL_LOCK_ARFCN 3

typedef enum
{
   CELL_LOCK_MODE_CONDITIONED = 0,
   CELL_LOCK_MODE_ABSOLUTE
} em_cell_lock_mode_enum;

typedef struct
{
   module_type    	mod_id; 
   em_info_enum 	em_info_event;
} em_info_req_mod_tbl_struct;

/* To identify the EM request from */
typedef enum                     
{
	EM_FROM_ELT, //replace EM_FROM_CATCHER
	EM_FROM_RMMI	/* tommy add for RMMI EM support */
} em_source_enum;

typedef enum
{
	EM_CAUSE_OK,
	EM_CAUSE_INVALID_INFO_TYPE
} em_err_cause_enum;

/*Byron: 2007/03/14: Add for request to RR from Engineering mode*/
typedef enum
{
    /*For quest to disable MT or not*/
    EM_MT_NOT_ALLOWED
} em_feature_enum;

/*Byron: 2007/03/14: Add for request to RR from Engineering mode*/
typedef enum
{
    /*For turn on the feature or not*/
    EM_FEATURE_ON,
    EM_FEATURE_OFF
} em_feature_state_enum;

/* local parameter structures */

/* For L4CPS_EM_UPDATE_REQ */
typedef struct
{
  kal_uint8 ref_count;
  kal_uint16 msg_len;
  em_source_enum   em_src;
  em_info_status_enum  info_request[NUM_OF_EM_INFO];
} l4cps_em_update_req_struct;

/*Byron: 2006/02/15: User can trigger RR to suspend cell reselection procedure in all state or transfer state*/
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 suspend_status; /* 0: in all RR states, 1: in RR GPRS transfer */
} l4cps_em_cell_resel_suspend_req_struct; 

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result; /* 0: in all RR states, 1: in RR GPRS transfer */
   kal_uint8 cause;
}l4cps_em_cell_resel_suspend_cnf_struct;

typedef l4cps_em_cell_resel_suspend_cnf_struct l4cps_em_cell_resel_resume_cnf_struct;

/*Byron: 2006/08/06: Add for cell lock*/
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool band_indicator; /* 0: not 1900 band cell, 1: 1900 band cell*/
    kal_uint32 enabled_bitmap; /* Ex: 00000101 => The 1st and 3rd index of the array "lock_arfcn" are valid */
    kal_uint16 lock_arfcn[MAX_NUM_CELL_LOCK_ARFCN]; /* The cell's arfcn to be locked*/
    em_cell_lock_mode_enum mode;
}l4cps_em_set_cell_lock_req_struct;

/*Byron: 2006/08/06: Add for cell lock*/
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result; /*0: Turn off, 1: Turn on*/
}l4cps_em_set_cell_lock_cnf_struct;

/*Byron: 2006/08/06: Add for cell lock*/
/* Zengyu 20100807: add header for this structure */
typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_bool band_indicator; /*0: not 1900 band cell, 1: 1900 band cell*/
    kal_uint32 enabled_bitmap; /* Ex: 00000101 => The 1st and 3rd index of the array "lock_arfcn" are valid */
    kal_uint16 lock_arfcn[MAX_NUM_CELL_LOCK_ARFCN]; /* The cell's arfcn to be locked*/
    em_cell_lock_mode_enum mode;
}l4cps_em_get_cell_lock_cnf_struct;

/*Byron: 2007/03/14: Add for request to RR from Engineering mode*/
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    em_feature_enum em_feature;
    em_feature_state_enum em_feature_state;
} l4cps_em_feature_command_req_struct;

/*Byron: 2007/03/14: Add for request to RR from Engineering mode*/
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    em_feature_enum em_feature;
    kal_bool result; /*0: Fail, 1: Success*/
} l4cps_em_feature_command_cnf_struct;

/* For L4CPS_EM_START_CNF, L4CPS_EM_STOP_CNF */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool	result;
   kal_uint8	cause;
   request_info_type	info_request;
} l4cps_em_start_cnf_struct;

typedef l4cps_em_start_cnf_struct l4cps_em_stop_cnf_struct;

/*091020 shuang SHUANG_EM_UT shuang move to the buttom of the rr em structures 
  because codegen, the struct declare should be in front of 
  the using*/
  
/* For L4CPS_EM_STATUS_IND */
/* James 2012/8/15 */
#ifndef __MTK_TARGET__
typedef struct l4cps_em_info_req_struct_tag
#else
typedef struct
#endif
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   em_info_enum em_info;
} l4cps_em_info_req_struct;

typedef l4cps_em_info_req_struct l4cps_em_status_ind_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* brwang, 20070727, [EM Cell ID Lock function] { */    

#define L4C_MAX_EM_CELL_LOCK_NUM 16
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8		 num_of_nc_lai;
   rr_em_lai_info_struct nc_lai[L4C_MAX_EM_CELL_LOCK_NUM];
} l4cps_em_set_cell_id_lock_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result; 
} l4cps_em_set_cell_id_lock_cnf_struct;

/* brwang, 20070727, [EM Cell ID Lock function]  } */    

/*mtk00924: 061106 add for network event notify*/
typedef struct
{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_bool 	is_on;
} l4cps_em_nw_event_notify_req_struct;

typedef struct
{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_bool 	result;
} l4cps_em_nw_event_notify_cnf_struct;

typedef struct
{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_uint8 group_id;
	kal_uint32 event_id;
} l4cps_em_nw_event_notify_ind_struct;


/* this is the header for local parameter of EM information 
   please define your EM local parameter as below:
typedef struct
{
    LOCAL_PARA_HDR
    em_info_enum em_info;
    your_em_info_type your_em_info;
} your_em_struct;
*/
typedef struct
{
    LOCAL_PARA_HDR
    em_info_enum em_info;
} l4cps_em_info_ind_hdr_struct;

#endif /* ~_EM_STRUCT_H */

