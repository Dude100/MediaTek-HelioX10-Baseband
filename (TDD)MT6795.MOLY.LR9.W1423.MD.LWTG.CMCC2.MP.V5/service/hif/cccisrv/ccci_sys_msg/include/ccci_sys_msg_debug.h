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
 *   ccci_sys_msg_debug.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI SYS MSG debug level configuration and macros
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * 
 ****************************************************************************/
#ifndef _CCCI_SYS_MSG_DEBUG_H
#define _CCCI_SYS_MSG_DEBUG_H

#if defined(__MTK_TARGET__)
    #define HIF_CONSOLE_TRACE_ENABLED   0 /* TODO: set it to 0 once DHL log is done on target. */
#else
    #define HIF_CONSOLE_TRACE_ENABLED   0
#endif

#include "hif_trace.h"
#include "ccci_sys_msg_trace.h"

#define CCCI_SYS_MSG_DBG_TH         CCCI_SYS_MSG_TRACE
typedef enum _ccci_sys_msg_dbg_level {
        CCCI_SYS_MSG_TRACE = 0,
        CCCI_SYS_MSG_INFO,
        CCCI_SYS_MSG_WARN,
        CCCI_SYS_MSG_ERR,
        CCCI_SYS_MSG_OFF = 0xFF,
}ccci_sys_msg_dbg_level;


#define CCCI_SYS_MSG_MOD_NORM      0x00000001
#define CCCI_SYS_MSG_MOD_UT        0x00000002
#define CCCI_SYS_MSG_MOD_IT        0x00000004
#define CCCI_SYS_MSG_MOD_MISC      0x00000008
#define CCCI_SYS_MSG_DBG_MSK       (CCCI_SYS_MSG_MOD_NORM| CCCI_SYS_MSG_MOD_UT| CCCI_SYS_MSG_MOD_IT| CCCI_SYS_MSG_MOD_MISC)

#define __ccci_sys_msg_err_printf  hif_trace_error
#define __ccci_sys_msg_info_printf hif_trace_info

#define ccci_sys_msg_trace(level, mod, ...)\
do{\
    if(KAL_TRUE != INT_QueryExceptionStatus()){\
        if (level >= CCCI_SYS_MSG_DBG_TH) {\
            if (mod & CCCI_SYS_MSG_DBG_MSK) {\
                if (level == CCCI_SYS_MSG_ERR) {\
                    __ccci_sys_msg_err_printf(__VA_ARGS__);\
                }else{\
                    __ccci_sys_msg_info_printf(__VA_ARGS__);\
                }\
            }\
        }\
    }\
}while(0)       \

#endif /* _CCCI_SYS_MSG_DEBUG_H */
