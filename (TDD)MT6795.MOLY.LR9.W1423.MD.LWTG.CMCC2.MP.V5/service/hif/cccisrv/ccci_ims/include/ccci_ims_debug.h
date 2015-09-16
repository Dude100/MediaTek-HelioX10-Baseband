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
 *   ccci_ims_debug.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI_IMS debug level configuration and macros
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
 * 03 27 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * [CCCI] CCCI_IMS 1st verison loopback support
 ****************************************************************************/
#ifndef _CCCI_IMS_DEBUG_H
#define _CCCI_IMS_DEBUG_H

#define HIF_DATA_TRACE_ENABLED          1

#if defined(__MTK_TARGET__)
    #define HIF_CONSOLE_TRACE_ENABLED   0 /* TODO: set it to 0 once DHL log is done on target. */
#else
    #define HIF_CONSOLE_TRACE_ENABLED   0
#endif

#include "hif_trace.h"
#include "ccci_ims_trace.h"
#include "TrcMod.h"

#define CCCI_IMS_DBG_TH	            CCCI_IMS_WARN
typedef enum _ccci_ims_dbg_level {
	CCCI_IMS_TRACE = 0,
	CCCI_IMS_INFO,
	CCCI_IMS_WARN,
	CCCI_IMS_ERR,
	CCCI_IMS_OFF = 0xFF,
}ccci_ims_dbg_level;

#define CCCI_IMS_MOD_INIT      0x00000001
#define CCCI_IMS_MOD_DATA      0x00000002
#define CCCI_IMS_MOD_IT        0x00000010
#define CCCI_IMS_DBG_MSK       (CCCI_IMS_MOD_INIT|CCCI_IMS_MOD_DATA|CCCI_IMS_MOD_IT)

#define ccci_ims_data_trace    hif_data_trace

void ccci_ims_print(kal_uint8 level, kal_uint32 mod, const char *fmt, ...);


#endif /* _CCCI_IMS_DEBUG_H */
