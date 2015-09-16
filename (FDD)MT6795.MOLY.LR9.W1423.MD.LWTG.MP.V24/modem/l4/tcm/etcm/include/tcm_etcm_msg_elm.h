
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
 * removed!
 * removed!
 *
 * removed!
 *
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


#ifndef _TCM_ETCM_MSG_ELM_H
#define _TCM_ETCM_MSG_ELM_H


/* kals. */
#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
//#include "stack_msgs.h"

#include "tcm_etcm_cid.h"

#define ETCM_MSGELM_COOKIE (0x758A)

struct etcm_msgElm_s;

typedef kal_bool (*etcm_msgElmPutRejCb)     (struct etcm_msgElm_s *msg);
typedef kal_bool (*etcm_msgElmPutReqCb)     (struct etcm_msgElm_s *msg);
typedef kal_bool (*etcm_msgElmPutCnfCb)     (struct etcm_msgElm_s *msg);
typedef kal_bool (*etcm_msgElmInputChkCb)   (struct etcm_msgElm_s *msg);
typedef kal_bool (*etcm_msgElmOutputGenCb)  (struct etcm_msgElm_s *in, struct etcm_msgElm_s *out);
typedef kal_bool (*etcm_msgElmCleanCb)     (struct etcm_msgElm_s *msg);

typedef struct etcm_msgElmOper_s {
    /*
    etcm_msgElmPutReqCb     reqCb;
    etcm_msgElmPutRejCb     rejCb;
    etcm_msgElmPutCnfCb     cnfCb;
    */
    etcm_msgElmInputChkCb inChkCb;
    etcm_msgElmOutputGenCb outGenCb;
    etcm_msgElmCleanCb cleanCb;
} etcm_msgElmOper_struct;

typedef kal_uint16 etcm_msgElm_rjc_struct; /* reject cause */

typedef struct etcm_msgElm_s {
    msg_type msg_id;
    etcm_msgElm_rjc_struct rej_cause;    /* used to record reject cause */
    module_type dst_mod;
    sap_type sap;
    etcm_cid_struct cid;
    local_para_struct         *m;
    etcm_msgElmOper_struct    *oper;
    void                      *parent;
    kal_bool hasGen;                  /* record the message has been gen or not */
    kal_uint32 cookie;
} etcm_msgElm_struct;

etcm_cid_struct         etcm_msgElmChkCid     (etcm_msgElm_struct *msg);
etcm_cid_struct         etcm_msgElmGetCid     (etcm_msgElm_struct *msg);
kal_bool                etcm_msgElmSetCid     (etcm_msgElm_struct *msg, etcm_cid_struct cid);
kal_bool                etcm_msgElmInit       (etcm_msgElm_struct *msg, msg_type msg_id, void *local_para_ptr);
kal_bool                etcm_msgElmGenSet     (etcm_msgElm_struct *in, etcm_msgElm_struct *out);
kal_bool                etcm_msgElmIsInvalid  (etcm_msgElm_struct *msg);
kal_bool                etcm_msgElmSetOper    (etcm_msgElm_struct *msg, etcm_msgElmOper_struct *oper);
kal_bool                etcm_msgElmSetParent  (etcm_msgElm_struct *msg, void *parent);
void                   *etcm_msgElmGetParent  (etcm_msgElm_struct *msg);
etcm_msgElm_rjc_struct  etcm_msgElmGetRjc     (etcm_msgElm_struct *msg);
kal_bool                etcm_msgElmSetRjc     (etcm_msgElm_struct *msg, etcm_msgElm_rjc_struct rjc);

kal_bool                etcm_msgElmClean      (etcm_msgElm_struct *msg);

#endif /* _TCM_ETCM_MSG_ELM_H */
