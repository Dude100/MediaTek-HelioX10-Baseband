
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef _TCM_ETCM_MSG_CONTAINER_H
#define _TCM_ETCM_MSG_CONTAINER_H


/* kals. */
#include "kal_general_types.h"

#include "tcm_context.h"
#include "tcm_etcm.h"
#include "tcm_etcm_pti.h"
#include "tcm_etcm_msg_elm.h"
#include "tcm_etcm_cid.h"

#define ETCM_MAX_OUT_MSG    (12)
#define ETCM_MSG_CONT_COOKIE  (0x8F6B17)

#define ETCM_MSGCONT_CHKMSG(c)  \
    ETCM_ASSERT(c);                                   \
    ETCM_ASSERT(c->etcm);                             \
    ETCM_ASSERT((c->cookie== ETCM_MSG_CONT_COOKIE));  \

typedef struct etcm_msgCont_s {
    etcm_context_struct       *etcm;
    etcm_ptiElm_struct        *pti;
    etcm_ebi_struct lebi;
    etcm_msgElm_struct inMsg;
    kal_uint8 n_outMsg;
    etcm_msgElm_struct outMsg[ETCM_MAX_OUT_MSG];
    kal_uint8 n_outPrev;
    etcm_msgElm_struct outPrev[ETCM_MAX_OUT_MSG];
    kal_uint8 n_outNext;
    etcm_msgElm_struct outNext[ETCM_MAX_OUT_MSG];
    kal_bool hasSent;
    kal_bool isESM_mo;				/* [TFT MO/MT] for TFT applied to determine MO/MT response from NW */
    tft_info_struct           *tftInfo; /* [enhancement][single mode phase 2] #11 - stack size reduction */
    kal_uint32 cookie;
} etcm_msgCont_struct;

kal_bool                etcm_msgContInit            (etcm_msgCont_struct *cont, etcm_context_struct *etcm);
kal_bool                etcm_msgContDeInit          (etcm_msgCont_struct *cont);

etcm_context_struct     *etcm_msgContGetEtcm        (etcm_msgCont_struct *cont);
etcm_ptiMngr_struct     *etcm_msgContGetPtiMngr     (etcm_msgCont_struct *cont);
etcm_cidMngr_struct     *etcm_msgContGetCidMngr     (etcm_msgCont_struct *cont);

kal_bool                etcm_msgContSetPti          (etcm_msgCont_struct *cont, etcm_ptiElm_struct *pti);
kal_bool                etcm_msgContSetLebi         (etcm_msgCont_struct *cont, etcm_ebi_struct lebi);
etcm_ebi_struct         etcm_msgContGetLebi         (etcm_msgCont_struct *cont);
etcm_ptiElm_struct      *etcm_msgContGetPti         (etcm_msgCont_struct *cont);
etcm_ptiElm_struct      *etcm_msgContGetPtiByMsg    (etcm_msgElm_struct  *elm);

kal_bool                etcm_msgContPutMsg          (etcm_msgCont_struct *cont, msg_type msg_id, etcm_msgElm_rjc_struct rej_cause);
kal_bool                etcm_msgContPutPrevMsg      (etcm_msgCont_struct *cont, msg_type msg_id, etcm_msgElm_rjc_struct rej_cause);
kal_bool                etcm_msgContPutNextMsg      (etcm_msgCont_struct *cont, msg_type msg_id, etcm_msgElm_rjc_struct rej_cause);

kal_bool                etcm_msgContPtiProcess      (etcm_msgCont_struct *cont, etcm_ptiv_struct ptiv);
kal_bool                etcm_msgContChkByPtiv       (etcm_msgCont_struct *cont, etcm_ptiv_struct ptiv);

kal_bool                etcm_msgContGenMsg          (etcm_msgCont_struct *cont);

/* [enhancement][single mode phase 2] #11 - stack size reduction */
kal_bool                etcm_msgContGetTft          (etcm_msgCont_struct *cont, tft_info_struct *tft);

#endif /* _TCM_ETCM_MSG_CONTAINER_H */
