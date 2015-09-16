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
 *   cccitty_debug.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI TTY debug level configuration and macros
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 09 06 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCITTY_DEBUG_H
#define _CCCITTY_DEBUG_H

#define HIF_DATA_TRACE_ENABLED          1

#if defined(__MTK_TARGET__)
    #define HIF_CONSOLE_TRACE_ENABLED   0 /* TODO: set it to 0 once DHL log is done on target. */
#else
    #define HIF_CONSOLE_TRACE_ENABLED   0
#endif

#include "hif_trace.h"
#include "cccitty_trace.h"
#include "TrcMod.h"

#define CCCI_TTY_DBG_TH         CCCI_TTY_TRACE
typedef enum _cccitty_dbg_level {
        CCCI_TTY_TRACE = 0,
        CCCI_TTY_INFO,
        CCCI_TTY_WARN,
        CCCI_TTY_ERR,
        CCCI_TTY_OFF = 0xFF,
}cccitty_dbg_level;

#define CCCI_TTY_MOD_HMU       0x00000001
#define CCCI_TTY_MOD_SM        0x00000002
#define CCCI_TTY_MOD_HDR       0x00000004
#define CCCI_TTY_MOD_UL        0x00000008
#define CCCI_TTY_MOD_DL        0x00000010
#define CCCI_TTY_MOD_UT        0x00000020
#define CCCI_TTY_MOD_MISC      0x00000040
#define CCCI_TTY_DBG_MSK       (CCCI_TTY_MOD_HMU|CCCI_TTY_MOD_SM|CCCI_TTY_MOD_HDR|CCCI_TTY_MOD_UL|CCCI_TTY_MOD_DL|CCCI_TTY_MOD_UT|CCCI_TTY_MOD_MISC)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define __cccitty_err_printf  hif_trace_error
#define __cccitty_info_printf hif_trace_info
#endif

#define cccitty_data_trace    hif_data_trace

#define cccitty_trace(level, mod, ...)\
do{\
    if (level >= CCCI_TTY_DBG_TH) {\
        if (mod & CCCI_TTY_DBG_MSK) {\
            if (level == CCCI_TTY_ERR) {\
                __cccitty_err_printf(__VA_ARGS__);\
            }else{\
                __cccitty_info_printf(__VA_ARGS__);\
            }\
        }\
    }\
}while(0)       \

#endif /* _CCCITTY_DEBUG_H */
