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
 *   upcm_stats.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *  UPCM statistics
 *
 *
 * Author:
 * -------
 * -------
 *   
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * .
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  upcm_stats.h
 *
 *    Description:  Statistics of UPCM
 *
 *        Created:  2013/05/24 03:39:10
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */

#ifndef  UPCM_STATS_INC
#define  UPCM_STATS_INC

#include <upcm_enum.h>

typedef struct 
{
    /* For Default EPSB */
    kal_uint32 dft_rcv_ul_burst_v4v6;
    kal_uint32 dft_rcv_ul_burst_v4;
    kal_uint32 dft_rcv_ul_burst_v6;
    kal_uint32 dft_ul_no_match_tft_drop;
    kal_uint32 dft_ul_suspend_queue;

    kal_uint32 ul_bytes;
    kal_uint32 ul_gpds;
    kal_uint32 ul_bytes_pri;
    kal_uint32 ul_gpds_pri;

    kal_uint32 dl_bytes;
    kal_uint32 dl_gpds;

    kal_uint32 rollback_ul_times;
    kal_uint32 rcv_by_ebi_times;

    kal_uint32 pkt_filter_add;
    kal_uint32 pkt_filter_mod;
    kal_uint32 pkt_filter_del;
    kal_uint32 pkt_filter_delall;
    kal_uint32 pkt_filter_del_bearer;
}upcm_epsb_stats_t;

typedef struct 
{
    kal_uint32 loopback_sdus;
    kal_uint32 buffered_sdus;
    kal_uint32 delay_sdus;
}upcm_test_mode_stats_t;

typedef struct 
{
    upcm_epsb_stats_t      epsb[MAX_EPSB_NUM];
    /* The backup for previous activation */
    upcm_epsb_stats_t      pre_epsb[MAX_EPSB_NUM];

    upcm_test_mode_stats_t test_mode;
    kal_uint32 suspend_total;
    kal_uint32 resume_total;

    kal_uint32 actv_testmode;
    kal_uint32 deactv_testmode;
    kal_uint32 close_testloop;
    kal_uint32 open_testloop;
}upcm_stats_t;

/* 
 * This pointer will be inited in upcm_init
 */
extern upcm_stats_t *p_upcm_stats_g;
#endif   /* ----- #ifndef UPCM_STATS_INC  ----- */

