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
 *   uas_export_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *
 * ==========================================================================
 * $Log:$
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * <saved by Perforce>
 * 
 * 10 02 2012 ij.liao
 * removed!
 *
 * 05 23 2012 ij.liao
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * Add copyright header.
 ****************************************************************************/

#ifndef _UAS_EXPORT_API_H
#define _UAS_EXPORT_API_H

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "uas_common_enums.h"
#include "ratdm_shaq_api.h"


#ifdef __UMTS_FDD_MODE__

/* for DL ADM pool, the users shall be in the same task! */
#define UAS_DL_ADM_ALLOC(mem_ptr, alloc_size)    \
do{   \
    mem_ptr = UAS_DL_ADM_ALLOC_int(UAS_DL_ADM, alloc_size, __FILE__, __LINE__);    \
}while(0)

#define UAS_DL_ADM_FREE(mem_ptr)            UAS_DL_ADM_FREE_int(UAS_DL_ADM, mem_ptr, __FILE__, __LINE__)



/* For 2G RLC DL block first half memory use */
#define GRLC_DL_ADM_ALLOC_FIRST_PART(mem_ptr, alloc_size)    \
do{   \
    mem_ptr = UAS_DL_ADM_ALLOC_int(GRLC_DL_ADM_FIRST_PART, alloc_size, __FILE__, __LINE__);	  \
}while(0)

#define GRLC_DL_ADM_FREE_FIRST_PART(mem_ptr)            UAS_DL_ADM_FREE_int(GRLC_DL_ADM_FIRST_PART, mem_ptr, __FILE__, __LINE__)


/* For 2G RLC DL block second half memory use */
#define GRLC_DL_ADM_ALLOC_SECOND_PART(mem_ptr, alloc_size)    \
do{   \
    mem_ptr = UAS_DL_ADM_ALLOC_int(GRLC_DL_ADM_SECOND_PART, alloc_size, __FILE__, __LINE__);	  \
}while(0)

#define GRLC_DL_ADM_FREE_SECOND_PART(mem_ptr)            UAS_DL_ADM_FREE_int(GRLC_DL_ADM_SECOND_PART, mem_ptr, __FILE__, __LINE__)





extern void* UAS_DL_ADM_ALLOC_int(uas_dl_adm_index_enum alloc_idx, kal_uint32 alloc_size, char* filename, kal_uint32 line);
extern void UAS_DL_ADM_FREE_int(uas_dl_adm_index_enum free_idx, void* mem_ptr, char* filename, kal_uint32 line);

#ifdef __RATDM_UL_SHAQ__
/* ShareQ : Query function to decide if a data primitive is sent to (D)RLC */
extern kal_bool mMacIsTickAvailable(void);
/* used by RATDM to check whether to kick UL2 or not */
extern kal_bool urlc_realtime_shaq_query_if_need_kick_urlc(ExtendedRbId RbId, SHAQ_LLQUEUE_IDX packet_type);
extern kal_bool PdcpCheckShaqStatus(kal_uint8 nsapi, ExtendedRbId *RbId);
extern void PdcpUpdateSendSN(ExtendedRbId RbId, kal_uint16 npdu_num);

#endif

#endif /* __UMTS_FDD_MODE__ */

#ifdef __UMTS_TDD128_MODE__
extern kal_bool mMacIsTickAvailable(void);
kal_bool urlc_realtime_shaq_query_if_need_kick_urlc(ExtendedRbId RbId, SHAQ_LLQUEUE_IDX packet_type);
extern kal_bool PdcpCheckShaqStatus(kal_uint8 nsapi, ExtendedRbId *RbId);
extern void PdcpUpdateSendSN(ExtendedRbId RbId, kal_uint16 npdu_num);
#endif

/* Definition for Control_UE_Capability_Bitmask BEGIN*/
#define ENABLE_MT_NO_RESTRICT  0x01   /* [ALPS00289798][Softbank IOT][RAN-13-01-04] Allow MT call while all AC blocked. */
/* Definition for Control_UE_Capability_Bitmask END*/
/* Query the status of the capability represented by the capability_bit in Control_UE_Capability_Bitmask */
extern kal_bool RRCE_Is_Capability_Enable(kal_uint8 capability_bit);

#endif /* _UAS_EXPORT_API_H */

