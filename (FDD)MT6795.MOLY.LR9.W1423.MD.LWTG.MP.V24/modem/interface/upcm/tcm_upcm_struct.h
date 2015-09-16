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

/*******************************************************************************
 * Filename:
 * ---------
 *   tcm_upcm_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *   
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * add PDN Bind related structure and enum.
 *
 * removed!
 * removed!
 * add dns info for bearer act and pdn bind.
 *
 * removed!
 * removed!
 * change packet number from tftlib define macro.
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  tcm_upcm_struct.h
 *
 *    Description:  Shared structure between TCM and UPCM
 *
 *        Created:  2012/3/20 ?W?? 10:27:56
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */

#ifndef  TCM_UPCM_STRUCT_INC
#define  TCM_UPCM_STRUCT_INC

#include "kal_public_api.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "tftlib_common_enum.h"
#include "tftlib_common_struct.h"
#include "ipcore_upcm_struct.h"

typedef remote_v4addr_struct remote_v4addr_t;
typedef remote_v6addr_struct remote_v6addr_t;
typedef pkt_filter_struct pkt_filter_t;

typedef struct 
{

    LOCAL_PARA_HDR

    /*  NSAPI/EBI of activated PDP context/EPS bearer. */

    kal_uint8   bearer_id;     

    /* 
     * If the PDP is secondary, indicate UPCM which primary PDP context the bearer is linked with. 
     * If the PDP is primary, indicate the linked_nspai = nsapi.
     */
    kal_uint8   linked_bearer_id;

    /* If the PDP is secondary, indicate number of packet filter entries carried in packet filter lists */
    kal_uint8   pkt_filters_num;

    /*If the PDP is secondary, indicate UPCM packet filter list */
    pkt_filter_act_struct   pkt_filters[MAX_PACKET_FILTER_NUM*2];

    /* Address acquired by PDP context activation. */
    ip_addr_struct ip_addr; 

    /* DNS info. */
    dns_struct dns;
}tcm_upcm_bearer_act_req_struct;

typedef struct 
{

    LOCAL_PARA_HDR

    /* indicate number of nsapi/EBI entries carried in deact_nsapi_list.*/
    kal_uint8 bearer_num;

    /*NSAPI/EBI list of the deactivated PDP contexts*/
    kal_uint8 deact_bearer_list[11];
}tcm_upcm_bearer_deact_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR

    /*NSAPI/EBI of binding PDP context/EPS bearer. */
    kal_uint8 bearer_id;

    /* Selected network interface id. */
    kal_uint32 network_interface_id;

    /*
     * Indicate IPv4 or IPv6 or IPv4v6 to UPCM.
     * There is a case that a network interface may bind to one IPv4 and one IPv6,
     * IPCore will decide IP version and send to corresponding PDN connection.
     */

	/* 
	 * Currently we don't know how to handle PPP_ADDR_TYPE
	 * So UPCM will assert when meet this type
	 */
    ip_addr_struct  ip_addr;

    /* DNS info. */
    dns_struct dns;

}tcm_upcm_pdn_bind_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR 

    /* NSAPI/EBI of binding PDP context/EPS bearer. */
    kal_uint8 bearer_id; 

}tcm_upcm_pdn_unbind_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR 

    /* NSAPI/EBI of binding PDP context/EPS bearer. */
    kal_uint8 bearer_id; 

    /* Result of this binding. */
    ps_cause_enum error_result ;
    
} tcm_upcm_pdn_bind_cnf_struct ;


typedef struct 
{
    LOCAL_PARA_HDR 

    /* NSAPI/EBI of unbinding PDP context/EPS bearer. */
    kal_uint8 bearer_id; 

    /* Result of this unbinding. */
    ps_cause_enum error_result ;
    
} tcm_upcm_pdn_unbind_cnf_struct ;


typedef struct 
{
    LOCAL_PARA_HDR

    /* Indicate UPCM the packet filter modification is triggered by which PDP context/EPS bearer context */
    kal_uint8   bearer_id;

    /* indicate number of packet filter entries carried in packet filter lists */
    kal_uint8   pkt_filters_num;

    /*indicate UPCM packet filter list */
    pkt_filter_act_struct   pkt_filters[MAX_PACKET_FILTER_NUM*2];
}tcm_upcm_pf_update_req_struct;


#endif   /* ----- #ifndef TCM_UPCM_STRUCT_INC  ----- */
