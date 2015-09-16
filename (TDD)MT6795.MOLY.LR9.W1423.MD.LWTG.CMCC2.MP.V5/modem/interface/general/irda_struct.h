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
#ifndef _IRDA_STRUCT_H
#define _IRDA_STRUCT_H


/*Msg sent to TTP*/
typedef struct  
{
	kal_uint8 	ref_count;
	kal_uint16 	msg_len;			/* LOCAL_PARA_HDR */
	
	kal_uint8 	local_lsap_sel;
	kal_uint8 	remote_lsap_sel;
	kal_uint8 	disconnect_reason;		/* for disconnect primitive only */
	kal_uint8   return_code;			   /* return code for connect confirm primitive */
	kal_uint8 	remote_ap_lsap_sel;		/* LSAP selector get by IAS client, IAS only */
	kal_uint8 	class_name_index;		   /* index for IAS client to find class name */
	kal_uint8 	attribute_name_index;	/* index for IAS client to find attribute name */	
	kal_uint8 	ias_return_code;		   /* for IAS only */
	kal_uint16  open_time;              /* irda open period*/ 
} ttp_data_request_struct;

typedef ttp_data_request_struct irda_open_struct;
typedef ttp_data_request_struct ttp_connect_request_struct;                       
typedef ttp_data_request_struct ttp_connect_response_struct;                       
typedef ttp_data_request_struct ttp_disconnect_request_struct;                     
typedef ttp_data_request_struct lmp_data_request_struct;                           
typedef ttp_data_request_struct lmp_connect_request_struct;                        
typedef ttp_data_request_struct lmp_connect_response_struct;                       
typedef ttp_data_request_struct lmp_disconnect_request_struct;                     
typedef ttp_data_request_struct lmp_link_disconnect_request_struct;                
typedef ttp_data_request_struct ias_get_remote_lsap_sel_struct;                    
typedef ttp_data_request_struct lmp_data_indication_struct;                        
typedef ttp_data_request_struct lmp_connect_indication_struct;                     
typedef ttp_data_request_struct lmp_connect_confirm_struct;                        
typedef ttp_data_request_struct lmp_lsap_disconnect_indication_struct;             
typedef ttp_data_request_struct lmp_link_disconnect_indication_struct;             
typedef ttp_data_request_struct ias_get_remote_lsap_sel_confirm_struct;            
typedef ttp_data_request_struct ttp_data_indication_struct;                        
typedef ttp_data_request_struct ttp_connect_indication_struct;                     
typedef ttp_data_request_struct ttp_connect_confirm_struct;                        
typedef ttp_data_request_struct ttp_lsap_disconnect_indication_struct;             

#endif

