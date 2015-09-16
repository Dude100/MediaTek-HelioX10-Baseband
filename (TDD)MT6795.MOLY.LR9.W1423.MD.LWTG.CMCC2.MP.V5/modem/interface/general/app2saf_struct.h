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
 * app2saf_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of Applications and SAF.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _APP2SAF_STRUCT_H
#define _APP2SAF_STRUCT_H

#ifndef _SOC_API_H
#error pls include soc_api.h before app2saf_struct.h
#endif

#define SAF_MAX_SERVER_LEN          (64)    /* server string length constraint */
#define SAF_MAX_DERIVED_ADDR_NUM    (2)     /* number of derived addresses quering constraint */

/* The structure for specified the derived address */
typedef struct
{
   sockaddr_struct local_addr;          /* local address */
   sockaddr_struct derived_addr;        /* derived address from stun server */
} saf_addr_struct;

/* Used to open the channel */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint32  data_account_id;                 /* selected dataaccount for opening channel  */
   kal_char   stun_server[SAF_MAX_SERVER_LEN];  /* stun server (null terminated) */
   kal_uint16 stun_port;                        /* stun port number */   
   kal_char   turn_server[SAF_MAX_SERVER_LEN];  /* turn proto, not support yet */
   kal_uint16 turn_port;                        /* turn proto, not support yet */
} app_saf_open_channel_req_struct;

/* Used for confirmation of OPEN_CHANNEL_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 result;        /* saf_result_enum */
   kal_uint32 error_cause;  /* reserved, always return 0 now */
   kal_uint8  channel_id;   /* opened channel id */
} app_saf_open_channel_cnf_struct;

/* Used to abort OPEN_CHANNEL_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
      	
} app_saf_abort_open_channel_req_struct;

/* Used for confirmation of ABORT_OPEN_CHANNEL_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 result;        /* saf_result_enum */
   kal_uint32 error_cause;  /* reserved, always return 0 now */
} app_saf_abort_open_channel_cnf_struct;

/* Used to close the channel */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8  channel_id;   /* specified channel id */   
} app_saf_close_channel_req_struct;

/* Used for confirmation of CLOSE_CHANNEL_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 result;        /* saf_result_enum */
   kal_uint32 error_cause;  /* reserved, always return 0 now */
   kal_uint8  channel_id;   /* specified channel id */
} app_saf_close_channel_cnf_struct;

/* Used to get the derived IP address and port number */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 channel_id;    /* associated channel id */
   kal_uint32 request_id;   /* return same value in cnf */
   
   kal_uint8 stun_addr_num; /* identify the number of addresses need to query */
   kal_uint8 turn_addr_num; /* not support yet */
} app_saf_get_derived_addr_req_struct;

/* Used for confirmation of GET_DERIVED_ADDR_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 result;        /* saf_result_enum */
   kal_uint32 error_cause;  /* reserved, always return 0 now */
   kal_uint8  channel_id;   /* associated channel id */
   kal_uint32 request_id;   /* same value in req */
   saf_addr_struct stun_addr[SAF_MAX_DERIVED_ADDR_NUM]; /* associated stun address object array */
   kal_uint8       stun_addr_num;                       /* identify number of objects in array */
   saf_addr_struct turn_addr[SAF_MAX_DERIVED_ADDR_NUM]; /* turn proto, not support yet */
   kal_uint8       turn_addr_num;                       /* turn proto, not support yet */
} app_saf_get_derived_addr_cnf_struct;
					
/* Used to abort GET_DERIVED_ADDR_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 channel_id;    /* associated channel id */
   kal_uint32 request_id;   /* shall same as the one in req */
   
} app_saf_abort_get_derived_addr_req_struct;

/* Used for confirmation of ABORT_GET_DERIVED_ADDR_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 result;        /* saf_result_enum */
   kal_uint32 error_cause;  /* reserved, always return 0 now */
   kal_uint8  channel_id;   /* shall same as the one in req */
   kal_uint32 request_id;   /* same value in req */
      
} app_saf_abort_get_derived_addr_cnf_struct;

/* Used to get the NAT type */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 channel_id;    /* associated NAT type */
   
   /* TRUE: SAF will report SAF_RESTRICTED_CONE_NAT directly and 
       will not perform further test for distinguishing 
       whether it is Restricted Cone or Port Restricted Cone. 
       This can save the discovery time. */
   kal_bool not_care_port_restricted; 
   
} app_saf_get_nat_type_req_struct;

/* Used for confirmation of GET_NAT_TYPE_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 result;            /* saf_result_enum */
   kal_uint32 error_cause;      /* reserved, always return 0 now */
   kal_uint8  channel_id;       /* associated channel id */   
   kal_uint8 nat_type;          /* saf_nat_type_enum */

} app_saf_get_nat_type_cnf_struct;

/* Used to get the NAT binding lifetime */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 channel_id;            /* associated channel id */      
   kal_uint32 initial_trial_time; /* specifies the first lifetime SAF tried to test. 
                                     0: by default, in second */  
   kal_uint32 max_trial_count;    /* specifies the maximum of trials. 
                                     0: by default */   
   kal_uint32 max_trial_duration; /* specifies the maximum of trial duration which application could endure. 
                                     0: by default, in second */
   
} app_saf_get_nat_binding_lifetime_req_struct;

/* Used for confirmation of GET_NAT_BINDING_LIFETIME_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   
   kal_uint8 result;            /* saf_result_enum */
   kal_uint32 error_cause;      /* reserved, always return 0 now */
   kal_uint8  channel_id;       /* associated channel id */   
   kal_uint32 lifetime;         /* in second */

} app_saf_get_nat_binding_lifetime_cnf_struct;

/* The abort get nat type request and abort get derived addr request share the same structs */
typedef app_saf_abort_get_derived_addr_req_struct app_saf_abort_get_nat_type_req_struct;

/* The abort get nat lifetime request and abort get derived addr request share the same structs */
typedef app_saf_abort_get_derived_addr_req_struct app_saf_abort_get_nat_lifetime_req_struct;

/* The abort get nat type confirm and abort get derived addr confirm share the same structs */
typedef app_saf_abort_get_derived_addr_cnf_struct app_saf_abort_get_nat_type_cnf_struct;

/* The abort get nat lifetime confirm and abort get derived addr confirm share the same structs */
typedef app_saf_abort_get_derived_addr_cnf_struct app_saf_abort_get_nat_lifetime_cnf_struct;

#endif /* _APP2SAF_STRUCT_H */ 

