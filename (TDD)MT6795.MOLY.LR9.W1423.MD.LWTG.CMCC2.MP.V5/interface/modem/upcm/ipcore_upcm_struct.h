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
 *   ipcore_upcm_struct.h
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
 * 	Reply to MOD_TCM_N for many TCM instance case
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
 * add upcm_rcv_ul_by_ebi and add EBI for DL Deliver for IMS requirement.
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  ipcore_upcm_struct.h
 *
 *    Description:  IPCORE and UPCM ILM structures
 *
 *        Created:  2012/3/21 �W�� 11:30:09
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */
#ifndef  IPCORE_UPCM_STRUCT_INC
#define  IPCORE_UPCM_STRUCT_INC

#include "kal_public_api.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"

/* Valid bit length of IPv6 interface identifier from UPCM */
#define IPV6_VALID_IID_BITS (64)

/*
 * IPCORE just copy back the info to UPCM
 */
typedef struct
{
    kal_uint32 reply_dest_mod_id;
}upcm_ipcore_back_info_t;

typedef struct 
{
    LOCAL_PARA_HDR

    kal_uint32 network_interface_id;
    kal_uint8 pdn_id;
    kal_uint8 pad[2];

	/* 
	 * Currently we don't know how to handle PPP_ADDR_TYPE
	 * So UPCM will assert when meet this type
	 */
    ip_addr_struct  ip_addr;

    /* DNS info. */
    dns_struct dns;

    /*
     * IPCORE just copy back the info to UPCM
     */
    upcm_ipcore_back_info_t back_info;
}ipcore_upcm_pdn_bind_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR

    /* Same to ipcore_upcm_pdn_bind_ind_struct */
    kal_uint32 network_interface_id;
    kal_uint8 pdn_id;
    kal_uint8 pad[2];

    ip_addr_struct ip_addr;
    dns_struct dns;

    /* return value */
    ps_cause_enum result;   /* Success: HIF_IPC_OK, Error cause : HIF_IPC_PDN_BIND_RSP_XXX */

    /*
     * IPCORE just copy back the info to UPCM
     */
    upcm_ipcore_back_info_t back_info;
}ipcore_upcm_pdn_bind_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8 pdn_id;
}ipcore_upcm_pdn_deact_ind_struct;

/*
 * UPCM will fill DL info only on head GPD's SW control Info.
 * user use  QBM_DES_GET_SW_CTRL_FIELD(_p) to get this structure
 */
typedef struct
{
    kal_uint8 ebi;
}upcm_dlvr_dl_info_t;

#endif   /* ----- #ifndef IPCORE_UPCM_STRUCT_INC  ----- */

