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

/*******************************************************************************
 * Filename:
 * ---------
 *	cc_ss_defs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains Macros related to CC SS.
 *   
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _CC_SS_DEFS_H
#define _CC_SS_DEFS_H

/*****************
Include Statements
******************/

#include "cc_defs.h"
#include "cc_std_defs.h"
//#include "kal_release.h"
#include "kal_public_defs.h"

/************************
Macros Without Parameters 
*************************/
#define CC_SS_INVALID_ORIGIN 0
#define CC_SS_FROM_APP       1
#define CC_SS_FROM_PEER      2

/*-----------SS Operations----------------------------*/
/*Remove SS_NONE since this value is defined for old DTMF design.*/
//#define  SS_NONE	                              0 
#define  SS_PROCESS_UNSTRUCTURED_SS_REQUEST          59
#define  SS_UNSTRUCTURED_SS_REQUEST                  60
#define  SS_UNSTRUCTURED_SS_NOTIFY                   61
#define  SS_PROCESS_UNSTRUCTURED_SS_DATA             19
#define  SS_NOTIFY_SS                                16
#define  SS_CALL_DEFLECTION                         117
#define  SS_USER_USER_SERVICE                       118
#define  SS_ACCESS_REGISTERCCENTRY                  119
#define  SS_FORWARDCUG_INFO                         120
#define  SS_SPLIT_MPTY                              121
#define  SS_RETRIEVE_MPTY                           122
#define  SS_HOLD_MPTY                               123
#define  SS_BUILD_MPTY                              124
#define  SS_FORWARD_CHARGE_ADVICE                   125
#define  SS_EXPLICIT_CT                             126

/*-----------SS Operation Invoke Timeout Value-----------*/
/* Timeout Value in Milli Secs */

#define SS_INVOCATION_NOTIFY_TIMEOUT                (3*KAL_TICKS_5_SEC)  
#define SS_PROCESS_UNSTRUCTURED_SS_DATA_TIMEOUT     (3*KAL_TICKS_5_SEC)  
#define SS_PROCESS_UNSTRUCTURED_SS_REQUEST_TIMEOUT  (2*KAL_TICKS_30_SEC) 
#define SS_UNSTRUCTURED_SS_REQUEST_TIMEOUT          (2*KAL_TICKS_30_SEC) 
#define SS_UNSTRUCTURED_SS_NOTIFY_TIMEOUT           (2*KAL_TICKS_30_SEC) 
#define SS_FORWARD_CHARGE_ADVICE_TIMEOUT            KAL_TICKS_1_SEC    
#define SS_BUILD_MPTY_TIMEOUT                       (2*KAL_TICKS_5_SEC) 
#define SS_HOLD_MPTY_TIMEOUT                        (2*KAL_TICKS_5_SEC) 
#define SS_RETRIEVE_MPTY_TIMEOUT                    (2*KAL_TICKS_5_SEC) 
#define SS_SPLIT_MPTY_TIMEOUT                       (2*KAL_TICKS_5_SEC) 
#define SS_EXPLICIT_CT_TIMEOUT                      (3*KAL_TICKS_5_SEC)
#define SS_ACCESS_REGISTERCCENTRY_TIMEOUT           KAL_TICKS_30_SEC
#define SS_CALL_DEFLECTION_TIMEOUT                  KAL_TICKS_30_SEC
#define SS_USER_USER_SERVICE_TIMEOUT                (2*KAL_TICKS_5_SEC)  


/*-----------Class of SS Operations-----------------------*/
#define SS_CLASS_1                                  1
#define SS_CLASS_2                                  2
#define SS_CLASS_3                                  3
#define SS_CLASS_4                                  4

#define SS_PROTO_VER_2                           ( kal_uint8 )0x00
#define SS_PROTO_VER_3                           ( kal_uint8 )0x01
#define SS_ANY_PROTO_VER                         ( kal_uint8 )0xFF


/*********************
Macros With Parameters 
**********************/

#define cc_reset_inv_fsm(ti, inv_index)               \
{                                                     \
  CC_CTAB_CONTEXT(cc_ti_info[CC_CTAB_CONTEXT(cc_ti_pool[ti].\
	      ti_info_index)]       \
  .inv[inv_index].state)       =    \
  S_CC_INVOKE_IDLE;                   \
}

#endif  /*_CC_SS_DEFS_H*/
















