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
 *   ccmni_common.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI CCMNI local feature compile options and common data structure
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 05 14 2014 ap.wang
 * removed!
 * CCMNI Fast Ack Patch and linkdown fast reload
 *
 * removed!
 * removed!
 * 	[CCMNI ACK Fast Path]
 *
 * 09 06 2013 ap.wang
 * removed!
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
#ifndef _CCMNI_COMMON_H
#define _CCMNI_COMMON_H
#include "kal_public_api.h"
#include "ccmni_debug.h"
#include "hif_mw_msgid.h"


#define CCMNI_SWLA_ENABLE (0)
#if CCMNI_SWLA_ENABLE
#include "swla_public.h"    
#endif

/* Compile Options */
#if defined(ATEST_SYS_CCCI_CCMNI)
#define __CCMNI_UT__
#endif

/*! 
 *  __CCMNI_PERF__
 *  defined for CCMNI performance measurement
 */
//#define __CCMNI_PERF__
#ifdef __CCMNI_PERF__
#include "cpu.h"
#endif

#define CCMNI_EMCSNI0_PORT   0
#define CCMNI_IT_TX_PKT_SZ   1024

#if defined(__CCCI_LB_IT__)
#define __CCMNI_LB_IT__
#endif
#define __CCMNI_ACK_FAST_PATH__
#define _CCMNI_CCCI_SEQ_NO_

#define CCMNI_PFP_ENABLE     0 /*reserved for future PFP, fixed to 0*/
/* EtherCore drops invalid/ARP packets, need reload from CCMNI*/
#define CCMNI_RELOAD_ENABLE  0 /*reserved for future EtherCore connection, fixed to 0*/

#ifdef __CCMNI_PERF__
#define CCMNI_PROF_REC_CNT  256
typedef struct _CCMNI_profile_t{
    kal_uint32  ccmni_normal_hif_poll_queue_s; 
    kal_uint32  ccmni_normal_hif_poll_queue_e; 
    kal_uint32  ccmni_normal_hif_poll_queue_t;

    kal_uint32  ccmni_tx_poll_queue_s[20];
    kal_uint32  ccmni_tx_poll_queue_e[20];        
    kal_uint32  ccmni_tx_poll_queue_t[20];
    kal_uint32  tx_idx;

    kal_uint32  ccmni_rx_poll_queue_s[20];
    kal_uint32  ccmni_rx_poll_queue_e[20];        
    kal_uint32  ccmni_rx_poll_queue_t[20];
    kal_uint32  rx_idx;
} CCMNI_profile_t;
extern CCMNI_profile_t ccmni_prof_rec[CCMNI_PROF_REC_CNT];
extern kal_uint32 CCMNI_prof_idx;
#endif

//4 <UT TEST CONFIG>
/*********************************************************************************************************
20120622: UT test proposal
1. enable LTM_SIMULATION_SUPPORT in MT6290_LTE_FEATURES.mak, it will make LTM_SIM keep put packets in DL
2. implement lms_abs_write_gpds to receive and check the loopback packet
3. enable loopback in SDIO
*********************************************************************************************************/

#endif //#ifndef _CCMNI_COMMON_H
