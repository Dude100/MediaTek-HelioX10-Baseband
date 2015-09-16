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
 *
 * Filename:
 * ---------
 * customer_ps_inc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for include file of PS customization parameters. 
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOMER_PS_INC_H
#define _CUSTOMER_PS_INC_H
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#define CM_SMS_MAX_ARMSG_NUM             100 
#endif
/* For customer define SMS message box number. */
/* This parameter means total number of SMS stored in SIM and NVRAM can be read.  */

/* This value is to define the maximun segment number of EMS short message. */
#ifdef __EMS_REL5__
#define MMI_SMS_MAX_MSG_SEG 8
#else
#define MMI_SMS_MAX_MSG_SEG 4
#endif

/* In later branch, each entry costs (46 + 2* MMI_SMS_MAX_MSG_SEG) bytes.  */
#define CM_SMS_MAX_MSG_NUM        SMS_TOTAL_ENTRY

/* From 3GPP 23.040, if __EMS_REL5__ is NOT turned ON, segment number shall be  */
/* larger than 8 segments.                                                      */
#ifdef __EMS_REL5__
#if MMI_SMS_MAX_MSG_SEG < 8
#error segment number shall be larger than 8 for EMS 5.0
#endif
 
#endif

/* The value defines the buffer size for EMS objects, such as pre-defined animation. */
/* The more of buffer size would support more objects numbers.                       */
#define EMS_OBJ_BUFF_SIZE_PER_SEG  300

/* For EMS 5.1, the buffer for raw data of objects is separated to another memory pool. */
/* The pool size is (MMI_SMS_MAX_MSG_SEG * 140 * EMS_RATIO_OF_OBJ_PDU_BUFF).        */
/* 140 is the max size of a SMS                                                           */

/* The more of EMS_RATIO_OF_OBJ_PDU_BUFF value will support    */
/* the larger objects which is compressed in higher compression ratio.   */

/* The ratio can be a float value, for example, 1.5, 2.5 */

#ifdef __EMS_REL5__
#define EMS_RATIO_OF_OBJ_PDU_BUFF 2 
#endif


/* TOTAL memory cost in EMS library : */
/* If __EMS_REL5__ is NOT turned ON : */
/* memory costs = 2 * CM_SMS_MAX_MSG_NUM * (EMS_OBJ_BUFF_SIZE_PER_SEG + 310) bytes */

/* If __EMS_REL5__ is turned ON : */
/* memory costs = 2 * CM_SMS_MAX_MSG_NUM * (EMS_OBJ_BUFF_SIZE_PER_SEG + 310 +          */
/*                                          140 *EMS_RATIO_OF_OBJ_PDU_BUFF) bytes */

/* ps: 310 bytes per segment are for text string buffer */


/* display when concatenated  segment missed */
/* for example: a 3-segment concatenated message, but 2nd segment misses. */
/* MMI would show :   "content of seg1(.....)content of seg3 " */
/* Note :DO NOT use the UCS2 coding string . */
#define EMS_MISS_SEG_DELIMIT_STR   "(.....)"   

//#include "customer_email_num.h"

#ifndef __OPTR_NONE__
    #include "op_custom_ps_inc.h"
#endif

/* =========================================================================== */

#endif /* _CUSTOMER_PS_INC_H */

