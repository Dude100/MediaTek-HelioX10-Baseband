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
 *   cccitty_common.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI TTY common compile option and macros
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
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCITTY_COMMON_H
#define _CCCITTY_COMMON_H
#include "syscomp_config.h"
#include "kal_public_api.h"
#include "cccitty_debug.h"
#include "dcl.h"
#include "qmu_bm.h"
#include "hif_mw_msgid.h"

#if defined (ATEST_SYS_CCCI_TTY)
#define __CCCITTY_UT__
#endif
//#define __CCCITTY_EXCEPT_TODO__ /* disable the place that need to implement the exception mode*/

//#define CCCITTY_LB_ENABLE


#define CCCI_TTY_COM_ID_MIN uart_port_ccci_start
#define CCCI_TTY_COM_ID_MAX uart_port_ccci_end
#define CCCI_TTY_COM_ID_CNT (CCCI_TTY_COM_ID_MAX - CCCI_TTY_COM_ID_MIN + 1)

/*use mutext api to protect thread safe*/
#define CCCI_TTY_LOCK(_s)   kal_take_enh_mutex(_s)
#define CCCI_TTY_UNLOCK(_s) kal_give_enh_mutex(_s)

#define CCCITTY_UARTP_TO_DEVID(_uartport) (_uartport-CCCI_TTY_COM_ID_MIN)
#define CCCITTY_DEVID_TO_UARTP(_devid) (_devid+CCCI_TTY_COM_ID_MIN)

DCL_STATUS cccitty_ttyc_hdr_cmd_get_chunk_size(UART_PORT port, DCL_UINT32 *p_chunkSize);
DCL_STATUS cccitty_ttyc_hdr_cmd_get_mtu_size(UART_PORT port, DCL_UINT32 *p_dlMTUSize, DCL_UINT32 *p_ulMTUSize);

#if defined (ATEST_SYS_CCCI_TTY)
/* CCCI_UT Exception APIs*/
kal_int32 cccitty_ut_except_clear_ch(kal_uint32 ccci_ch);
kal_int32 cccitty_ut_except_set_gpd(kal_uint32 expt_ch, void *p_first_gpd, void *p_last_gpd);
kal_int32 cccitty_ut_except_poll_gpd(kal_uint32 expt_ch, void **pp_first_gpd, void **pp_last_gpd, kal_uint32 *gpd_num);
kal_int32 cccitty_ut_except_hif_st(kal_uint32 expt_dl_ch);
kal_int32 cccitty_ut_except_hif_isr(kal_uint32 expt_dl_ch);
#endif

#endif //#ifndef _CCCITTY_COMMON_H
