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
 *   ccmni_debug.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI CCMNI debug level configuration and macros
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 27 2013 ap.wang
 * removed!
 * CCMNI L2 trace
 *
 * removed!
 * removed!
 * Rename project name as MT6290
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCMNI_DEBUG_H
#define _CCMNI_DEBUG_H

#define HIF_DATA_TRACE_ENABLED          1

#if defined(__MTK_TARGET__)
    #define HIF_CONSOLE_TRACE_ENABLED   0 /* TODO: set it to 0 once DHL log is done on target. */
#else
    #define HIF_CONSOLE_TRACE_ENABLED   0
#endif

#include "hif_trace.h"
#include "ccmni_trace.h"
#include "TrcMod.h"

#define CCMNI_DBG_TH	            CCMNI_TRACE
typedef enum _ccmni_dbg_level {
	CCMNI_TRACE = 0,
	CCMNI_INFO,
	CCMNI_WARN,
	CCMNI_ERR,
	CCMNI_OFF = 0xFF,
}ccmni_dbg_level;

#define CCMNI_MOD_HMU       0x00000001
#define CCMNI_MOD_SM        0x00000002
#define CCMNI_MOD_UL        0x00000004
#define CCMNI_MOD_DATA      0x00000008
#define CCMNI_MOD_DL        0x00000010
#define CCMNI_MOD_UT        0x00000020
#define CCMNI_MOD_RGPDMGR   0x00000040
#define CCMNI_MOD_IT        0x00000080
#define CCMNI_DBG_MSK       (CCMNI_MOD_HMU|CCMNI_MOD_SM|CCMNI_MOD_UL|CCMNI_MOD_DL|CCMNI_MOD_DATA|CCMNI_MOD_RGPDMGR|CCMNI_MOD_UT|CCMNI_MOD_IT)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define __ccmni_err_printf  hif_trace_error
#define __ccmni_info_printf hif_trace_info
#endif
#define ccmni_data_trace    hif_data_trace

#define ccmni_trace(level, mod,...)\
do{\
    if (level >= CCMNI_DBG_TH) {\
        if (mod & CCMNI_DBG_MSK) {\
            if (level == CCMNI_ERR) {\
                __ccmni_err_printf(__VA_ARGS__);\
            }else{\
                __ccmni_info_printf(__VA_ARGS__);\
            }\
        }\
    }\
}while(0)\

#endif /* _CCMNI_DEBUG_H */
