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
 *   ccci_ut.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI UT related APIs
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
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI] CCCI/CLDMA INT
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCI_UT_H
#define _CCCI_UT_H

#ifdef ATEST_SYS_CCCI
#include "ccci_if.h"
#include "ccci_common.h"

typedef enum
{
    CCCI_UT_BUFF_TX0    = 0,
    CCCI_UT_BUFF_RX0    = 1,
    CCCI_UT_BUFF_TX1    = 2,
    CCCI_UT_BUFF_RX1    = 3,
    CCCI_UT_GPD_NOCB_TX0     = 4,
    CCCI_UT_GPD_RX0     = 5,
    CCCI_UT_GPD_TX1     = 6,
    CCCI_UT_GPD_RX1     = 7,
    CCCI_UT_GPD_TX2     = 8,
    CCCI_UT_GPD_RX2     = 9,
    CCCI_UT_BUFF_TX2    = 10,
    CCCI_UT_BUFF_RX2    = 11,
    CCCI_UT_MAX_CHANNEL = 12,
} CCCI_UT_CHANNEL_T;

typedef enum
{
    UT_HIF_TXQ_Q0 = 0,
    UT_HIF_TXQ_Q1 = 1,
    UT_HIF_TXQ_Q2 = 2,
    UT_HIF_TXQ_MAX = 5,
} CCCI_UT_HIF_TX_QUEUE;
typedef enum
{
    UT_HIF_RXQ_Q0 = 0,
    UT_HIF_RXQ_Q1 = 1,
    UT_HIF_RXQ_Q2 = 2,    
    UT_HIF_RXQ_MAX = 5,
} CCCI_UT_HIF_RX_QUEUE;

typedef enum
{
    CCCI_UT_PEER_ID_MIN	= 0,
	CCCI_UT_PEER_ID_AP_MD	= CCCI_UT_PEER_ID_MIN,
	CCCI_UT_PEER_ID_MD1_MD2,
	CCCI_UT_PEER_ID_MAX,
} CCCI_UT_PEER_ID;


typedef struct _ccci_ut_hif_inst {
    /*!
     *  @brief Tx queue CCCI callback function 
     */
    HIF_CCCI_GPD_CALLBACK             ccci_gpd_tx_cb_funp[UT_HIF_TXQ_MAX]; // = ccci_dl_cb
    /*!
     *  @brief Tx queue CCCI callback function 
     */
    HIF_CCCI_GPD_CALLBACK             ccci_gpd_rx_cb_funp[UT_HIF_RXQ_MAX]; // = ccci_ul_cb
    /*!
     *  @brief Tx queue CCCI callback function 
     */
    HIF_CCCI_BUFF_CALLBACK            ccci_buff_tx_cb_funp[UT_HIF_TXQ_MAX];
    /*!
     *  @brief Tx queue CCCI callback function 
     */
    HIF_CCCI_BUFF_CALLBACK            ccci_buff_rx_cb_funp[UT_HIF_RXQ_MAX];
    /*!
     *  @brief KAL_TRUE: loopback mode 
     */
    kal_bool                          lb_mode;
} ccci_ut_hif_inst;

kal_bool ccci_ut_st_create();
ccci_hw_apis ccci_ut_get_hif_apis(kal_uint32 hif_type);
kal_uint32 ccci_ut_get_lb_rx_ch(kal_uint32 tx_ch_id);
void ccci_ut_format_mb_gpd(ccci_io_request_t* ior, kal_uint32 gpd_num, kal_uint32 start_serial, kal_uint32 mb_id, CCCI_CHANNEL_T ch);
#endif

#endif //#ifndef _CCCI_UT_H
