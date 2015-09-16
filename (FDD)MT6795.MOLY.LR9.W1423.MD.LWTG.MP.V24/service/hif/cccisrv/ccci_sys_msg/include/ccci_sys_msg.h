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
 *   ccci_sys_msg.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI SYSTEM MESSAGE configuration and APIs
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * 
 ****************************************************************************/
#ifndef _CCCI_SYS_MSG_H
#define _CCCI_SYS_MSG_H

#include "ccci_if.h"
#include "cccidev_qbm.h"
#include "kal_public_api.h"
#include "ccci_sys_msg_debug.h"
#include <stdio.h>
#include <string.h>

/* For CCCI_RPC Atest*/
#ifdef ATEST_SYS_CCCI_SYS_MSG
#define __CCCI_SYS_MSG_UT__
#endif

#define CCCI_SYS_MSG_MOD    MOD_CCCIMSG

//#define CCCI_SYS_MSG_UL_BUF_TYPE             QBM_TYPE_CCCI_COMM         /* Type of GPD used in uplink data path. */
//#define CCCI_SYS_MSG_UL_BUF_SZ               QBM_CCCI_COMM_DATA_LEN
//#define CCCI_SYS_MSG_DL_BUF_TYPE             QBM_TYPE_CCCI_COMM         /* Type of GPD used in uplink data path. */
//#define CCCI_SYS_MSG_DL_BUF_SZ               QBM_CCCI_COMM_DATA_LEN

//#define CCCI_SYS_MSG_GET_QBM_DATALEN          CCCIDEV_GET_QBM_DATALEN
//#define CCCI_SYS_MSG_SET_QBM_DATALEN          CCCICOMM_SET_QBM_DATALEN
//#define CCCI_SYS_MSG_GET_QBM_DATAPTR          CCCIDEV_GET_QBM_DATAPTR
//#define CCCI_SYS_MSG_GET_GPD_LIST_SIZE        CCCIDEV_GET_GPD_LIST_SIZE
//#define CCCI_SYS_MSGS_GET_NONBPS_GPD_LIST_SIZE CCCIDEV_GET_NONBPS_GPD_LIST_SIZE
//#define CCCI_SYS_MSG_FIX_IOR_NULL_LAST        CCCIDEV_FIX_IOR_NULL_LAST
//#define CCCI_SYS_MSG_RM_CCCI_HEADERS          CCCIDEV_RM_CCCI_HEADERS
//#define CCCI_SYS_MSG_RST_GPD_LIST             CCCIDEV_RST_CCCI_COMM_GPD_LIST


typedef struct _ccci_sys_msg_inst_t {
    
    /* <CCCI released APIs> */
    kal_int32           (*ccci_init)(CCCI_CHANNEL_T channel, CCCI_CALLBACK funp);
    kal_bool            (*ccci_send_message)(kal_uint32 message, kal_uint32 reserved);
} ccci_sys_msg_inst_t;

typedef enum
{
    CCCI_ACK_DONE = 0,
    CCCI_MD_SLEEP_LOCK = 1,
    CCCI_MD_SLEEP_UNLOCK = 2
}CCCI_MD_SLEEP_CONTROL;

extern kal_bool INT_QueryExceptionStatus(void);
void ccci_system_channel_runtime_callback(CCCI_BUFF_T *bufp);
void ccci_sys_msg_dlcb_dummy(CCCI_BUFF_T *bufp);

#endif //_CCCI_SYS_MSG_H