
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
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *============================================================================
 ****************************************************************************/

#ifndef _TCM_ETCM_CID_H
#define _TCM_ETCM_CID_H

#include "kal_general_types.h"

/*etcm headers */
#include "tcm_etcm_def.h"

#define ETCM_EBI_INVALID  (0)

#if 0 /*__ETCM_UT__, no reason for ebi is 20 ?*/
/* under construction !*/
#else
#define ETCM_EBI_MAX      (15)
#endif
#define ETCM_EBI_MIN      (5)

#define ETCM_EBI_ISVALID(e)  (( ETCM_EBI_MIN <= e ) && ( e <= ETCM_EBI_MAX ))

/* CID Definition */
#define ETCM_CID_INVALID     TCM_INVALID_CONTEXT_ID /* 0xEE */
/*#define ETCM_CID_ISVALID(c)  (c != ETCM_CID_INVALID)*/
#define ETCM_CID_ISVALID(c)  (tcm_is_context_id_valid(c) && (c != ETCM_CID_INVALID))


typedef kal_uint8 etcm_cid_struct;
typedef kal_uint8 etcm_ebi_struct;
typedef void      *etcm_sib_struct;

typedef struct etcm_cidMngr_s {
    void *none;
} etcm_cidMngr_struct;

void               *etcm_cidGetSibPtr           (etcm_cid_struct cid );
kal_uint8           etcm_cidGetCIndex           (etcm_cid_struct cid );

kal_bool            etcm_cidIsPrimary           (etcm_cid_struct cid);
kal_bool            etcm_cidIsSecondary         (etcm_cid_struct cid);
kal_bool            etcm_cidSetSecondary        (etcm_cid_struct cid);
kal_bool            etcm_cidSetEbi              (etcm_cid_struct cid, etcm_ebi_struct ebi);
etcm_cid_struct     etcm_cidGetByEbi            (etcm_ebi_struct ebi);
etcm_cid_struct     etcm_cidGetNewByEbi         (etcm_ebi_struct ebi);

kal_bool            etcm_cidChkEbi              (etcm_ebi_struct ebi);
kal_bool            etcm_cidChkLebi             (etcm_ebi_struct lebi);
void                etcm_cidDump                (void);

/* cid context query api */
kal_bool            etcm_cidSetLebi             (etcm_cid_struct cid, etcm_ebi_struct lebi);
etcm_ebi_struct     etcm_cidGetLebi             (etcm_cid_struct cid);
etcm_ebi_struct     etcm_cidGetEbi              (etcm_cid_struct cid);
kal_bool            etcm_cidSetPrimary          (etcm_cid_struct cid, etcm_cid_struct pcid);
etcm_cid_struct     etcm_cidGetPrimary          (etcm_cid_struct cid);
kal_bool            etcm_cidDelRuntime          (etcm_cid_struct cid);

#endif
