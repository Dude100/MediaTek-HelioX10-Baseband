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


#ifndef _TCM_ETCM_FSM_H
#define _TCM_ETCM_FSM_H

/* kals. */
#include "kal_general_types.h"

/* struct. */
#include "l4c2tcm_struct.h"
#include "tcm2l4c_struct.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
//#include "stack_msgs.h"

/*etcm headers */
#include "tcm_etcm_def.h"
#include "tcm_etcm_msg_container.h"
#include "tcm_etcm.h"
#include "tcm_etcm_cid.h"
#include "tcm_etcm_utility.h"

typedef enum etcm_fsmAct_e {
    ETCM_FSM_ACT_NONE,
    ETCM_FSM_ACT_REQ,
    ETCM_FSM_ACT_CNF,
    ETCM_FSM_ACT_CNF_D,
    ETCM_FSM_ACT_REJ,
    ETCM_FSM_ACT_REJ_D,
    /* here we do not define Confirmation to prevent confuse with MT & MO call
     * all response of ETCM_STATE_ACT_CNF may be for Indication or for Confirmation.
     *  ???
    */
    ETCM_FSM_ACT_IND,
    ETCM_FSM_ACT_IND_D,

    ETCM_FSM_ACT_ASSERT,
    ETCM_FSM_ACT_ASSERT_D,

    ETCM_FSM_ACT_LAST
} etcm_fsmAct_struct;

typedef struct etcm_fsmTable_s {
    etcm_fsmAct_struct act;
    msg_type outMsg;
    tcm_fsm_state_enum next;
} etcm_fsmTable_struct;

kal_bool etcm_fsmProcess (etcm_cid_struct cid, etcm_fsmTable_struct *fsmTable, etcm_msgCont_struct *msgCont);
#endif /* _TCM_ETCM_FSM_H */

