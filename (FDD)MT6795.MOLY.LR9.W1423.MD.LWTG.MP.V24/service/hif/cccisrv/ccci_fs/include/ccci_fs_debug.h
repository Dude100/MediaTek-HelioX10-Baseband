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
 *   ccci_fs_debug.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI FS debug level configuration and macros
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI FS] Add CCCI FS DL trace log & sequence number between PS & L2
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCI_FS_DEBUG_H
#define _CCCI_FS_DEBUG_H

#define HIF_DATA_TRACE_ENABLED          1
#if defined(__MTK_TARGET__)
    #define HIF_CONSOLE_TRACE_ENABLED   0 /* TODO: set it to 0 once DHL log is done on target. */
#else
    #define HIF_CONSOLE_TRACE_ENABLED   0
#endif

#include "hif_trace.h"
#include "ccci_fs_trace.h"
#include "TrcMod.h"

#define CCCI_FS_DBG_TH         CCCI_FS_TRACE
typedef enum _ccci_fs_dbg_level {
        CCCI_FS_TRACE = 0,
        CCCI_FS_INFO,
        CCCI_FS_WARN,
        CCCI_FS_ERR,
        CCCI_FS_OFF = 0xFF,
}ccci_fs_dbg_level;

#define CCCI_FS_MOD_POLL_IO   0x00000001
#define CCCI_FS_MOD_NORM_IO   0x00000002
#define CCCI_FS_MOD_SHM       0x00000004
#define CCCI_FS_MOD_API       0x00000008
#define CCCI_FS_MOD_GPD       0x00000010
#define CCCI_FS_MOD_UT        0x00000020
#define CCCI_FS_MOD_IT        0x00000040
#define CCCI_FS_MOD_MISC      0x00000080
#define CCCI_FS_DBG_MSK       (CCCI_FS_MOD_POLL_IO| CCCI_FS_MOD_NORM_IO| CCCI_FS_MOD_SHM| CCCI_FS_MOD_API| CCCI_FS_MOD_UT| CCCI_FS_MOD_IT| CCCI_FS_MOD_GPD| CCCI_FS_MOD_MISC)


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define __ccci_fs_err_printf  hif_trace_error
#define __ccci_fs_info_printf hif_trace_info
#endif


#define ccci_fs_trace(level, mod, ...)\
do{\
    if(KAL_TRUE != INT_QueryExceptionStatus()){\
        if (level >= CCCI_FS_DBG_TH) {\
            if (mod & CCCI_FS_DBG_MSK) {\
                if (level == CCCI_FS_ERR) {\
                    __ccci_fs_err_printf(__VA_ARGS__);\
                }else{\
                    __ccci_fs_info_printf(__VA_ARGS__);\
                }\
            }\
        }\
    }\
}while(0)       \

void ccci_fs_data_trace_dump(kal_uint32 seq, kal_uint32 opid, void* p_data, kal_uint32 bytes);
#define ccci_fs_data_trace    hif_data_trace                
#define CCCI_FS_DL_DUMP_SIZE 48

#endif /* _CCCI_FS_DEBUG_H */
