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
 *   hmu_debug.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines HMU debug level configuration and macros
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 28 2013 ap.wang
 * removed!
 * 	[HMU] Add L2 trace for event trigger
 *
 ****************************************************************************/
#ifndef __HMU_DEBUG_H__
#define __HMU_DEBUG_H__

#define HIF_DATA_TRACE_ENABLED          1

#if defined(__MTK_TARGET__)
    #define HIF_CONSOLE_TRACE_ENABLED   0 /* TODO: set it to 0 once DHL log is done on target. */
#else
    #define HIF_CONSOLE_TRACE_ENABLED   0
#endif

#include "hif_trace.h"
#include "hmu_trace.h"
#include "TrcMod.h"

#define HMU_DBG_TH         HMU_TRACE
typedef enum _HMU_dbg_level {
        HMU_TRACE = 0,
        HMU_INFO,
        HMU_WARN,
        HMU_ERR,
        HMU_OFF = 0xFF,
}hmu_dbg_level;


#define HMU_MOD           0x00000001
#define HMU_DBG_MSK       (HMU_MOD)


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define __hmu_err_printf  hif_trace_error
#define __hmu_info_printf hif_trace_info
#endif

#define hmu_data_trace    hif_data_trace

#define hmu_trace(level, mod,...)\
do{\
    if (level >= HMU_DBG_TH) {\
        if (mod & HMU_DBG_MSK) {\
            if (level == HMU_ERR) {\
                __hmu_err_printf(__VA_ARGS__);\
            }else{\
                __hmu_info_printf(__VA_ARGS__);\
            }\
        }\
    }\
}while(0)\

#endif /* __HMU_DEBUG_H__ */

