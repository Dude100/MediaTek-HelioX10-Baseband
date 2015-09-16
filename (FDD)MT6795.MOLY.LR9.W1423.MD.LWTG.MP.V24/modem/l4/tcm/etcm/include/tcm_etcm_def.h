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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * $Log: tcm_etcm.h,v $
 *
 * removed!
 * removed!
 * 	eTCM asser review.
 *
 * removed!
 * removed!
 *  * 	. for [TFT MO/MT], [BCM PCO check]
 *
 * removed!
 * removed!
 * [ETCM] if NW Assign QCI is 128~254, do not translate to R99 QoS
 *
 * removed!
 * removed!
 * ETCM part
 *
 * removed!
 * removed!
 * [ETCM] MM IT merge back to MOLY TRUNK
 *
 * removed!
 * removed!
 * ETCM merge back to MOLY TRUNK
 *
 * removed!
 * removed!
 * [ETCM] Add ETCM module & UT
 * Revision 1.12  2012-05-08 01:46:27  mtk03537
 * CQ:WIMAX0000????
 * rename struct
 *------------------------------------------------------------------------------
*/

#ifndef _TCM_ETCM_DEF_H
#define _TCM_ETCM_DEF_H

/* msgid */
#include "l4_msgid.h"
#include "tst_msgid.h"
#include "eval_msgid.h"
#include "upcm_msgid.h"
#include "ppp_msgid.h"

/* sap */
#include "md_sap.h"
#include "md_mw_sap.h"
#include "tst_sap.h"

#ifndef __ETCM__
#error " ETCM module is not turn on !!"
#endif /* __ETCM__ */

#define __ETCM_UT__ 0

/* Operator Specific QoS QCI */
#define ETCM_OPERATOR_SPECIFIC_MIN_QCI 128
#define ETCM_OPERATOR_SPECIFIC_MAX_QCI 254
#define ETCM_QCI_IS_OPERATOR_SPECIFIC(v)   ((v >= ETCM_OPERATOR_SPECIFIC_MIN_QCI) && (v <= ETCM_OPERATOR_SPECIFIC_MAX_QCI))

#if 0 /* move to etcm_cid.h */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* PPP Dial-up */
#define MMI_CONFIG_PROTOCOL_PPP 0
#define __ETCM_DO_TFT_CONFLICT_DEACT__ 1
#define __ETCM_UT_FREE_PCO_TFT_POINTER__ 0

#if  defined(__ETCM__) && defined(__UGTCM__)
#define __ETCM_MULTI_MODE__ 1

#elif defined(__ETCM__) && !defined(__UGTCM__)
/* LTE single mode */
#undef  __ETCM_MULTI_MODE__

#elif !defined(__ETCM__) && defined(__UGTCM__)
#error "not support UGTCM single mode in ETCM module !!"

#else
#error "please set correct ug/e TCM option !!"

#endif

#endif /* _TCM_ETCM_DEF_H */

