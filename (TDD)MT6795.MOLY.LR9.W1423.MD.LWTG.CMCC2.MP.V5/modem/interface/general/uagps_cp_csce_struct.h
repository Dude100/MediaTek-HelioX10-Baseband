/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   uagps_cp_csce_struct.h
 *
 * Project:
 * --------
 *   AGPS
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log:$
 * 
 * removed!
 * removed!
 * 20120928_MOLY00004236_Adeline_Remove_stack_ltlcom.h_AGPS.xls.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * ULCS RHR
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 ****************************************************************************/

#ifndef _UAGPS_CP_CSCE_STRUCT_H
#define _UAGPS_CP_CSCE_STRUCT_H
#include "kal_general_types.h"
#include "kal_public_api.h"
typedef struct _plmn_id_internal_struct
{
	kal_uint8 mcc1;
	kal_uint8 mcc2;
	kal_uint8 mcc3;
	kal_uint8 mnc1;
	kal_uint8 mnc2;
	kal_uint8 mnc3;
} plmn_id_internal_struct;

typedef enum
{
    UAS_NO_SERVICE, 
	UAS_NORMAL_SERVICE, 
	UAS_LIMITED_SERVICE

} uas_service_state;

typedef enum
{
    SIB15_START_REQ_ENABLE, 
	SIB15_START_REQ_ONE_SHOT

} sib15_start_req;

/**************************************************************
 * UAGPS_CP_CSCE_START_SIB15_COLLECTION_REQ
 *
 * 
 ***************************************************************/   
typedef struct
{
    LOCAL_PARA_HDR

    sib15_start_req    start_req;

} uagps_cp_csce_start_sib15_collection_req_struct;

/**************************************************************
 * UAGPS_CP_CSCE_STOP_SIB15_COLLECTION_REQ
 *
 * 
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR

} uagps_cp_csce_stop_sib15_collection_req_struct;

/**************************************************************
 * UAGPS_CP_CSCE_START_SIB15_COLLECTION_CNF
 *
 * 
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR

} uagps_cp_csce_start_sib15_collection_cnf_struct;

/**************************************************************
 * UAGPS_CP_CSCE_STOP_SIB15_COLLECTION_CNF
 *
 * 
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR

} uagps_cp_csce_stop_sib15_collection_cnf_struct;

/**************************************************************
 * UAGPS_CP_CSCE_CELL_CHANGE_IND
 *
 * 
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR

    uas_service_state service_state;
    plmn_id_internal_struct plmn_id;
    kal_uint16 uarfcn;
    kal_uint16 phyCellId;

} uagps_cp_csce_cell_change_ind_struct;

#endif /* _UAGPS_CP_CSCE_STRUCT_H */
