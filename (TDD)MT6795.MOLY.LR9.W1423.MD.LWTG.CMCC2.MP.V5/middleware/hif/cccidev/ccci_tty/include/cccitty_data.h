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
 *   cccitty_data.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI TTY data path related functions and configuration
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
 * 	Shrink CCCI UL/DL buffer to 3.5KB
 *
 * removed!
 * removed!
 * [CCCI] Add ICUSB feature.
 *
 * 11 26 2013 box.wu
 * removed!
 * add exception, tty, ICUSB.
 *
 * removed!
 * removed!
 * Add new cmd support (TTY_CMD_GET_MTU_SIZE)
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCITTY_DATA_H
#define _CCCITTY_DATA_H
#include "cccitty_sm.h"
#include "qmu_bm.h"
#include "ccci_if.h"
#include "dcl.h"
#include "cccitty_sm.h"

#define CCCI_TTY_DL_BUF_TYPE            QBM_TYPE_CCCI_COMM         /* Type of GPD used in uplink data path. */
#define CCCI_TTY_UL_BUF_TYPE            QBM_TYPE_CCCI_COMM         /* Type of GPD used in uplink data path. */
#define CCCI_TTY_DL_BUF_SZ              (3584)//3.5KB defined by AP SKB restriction      
#define CCCI_TTY_UL_BUF_SZ              (3584)//3.5KB defined by AP SKB restriction
#define CCCI_TTY_UL_BUF_CNT             16                         /* Default: Reload 16 RGPDs for each CCCI TTY device. */
#define CCCI_TTY_UL_BUF_CNT_1ST_RELOAD  (CCCI_TTY_UL_BUF_CNT+1)    /* Default: 1 additional RGPD for tail */

/* CCCI_TTY_UL_BUF_CNT_1ST_RELOAD */
#define CCCI_TTY_DHL_TTL_RGPD_CNT       CCCI_TTY_UL_BUF_CNT_1ST_RELOAD  //17
#define CCCI_TTY_TST_TTL_RGPD_CNT       CCCI_TTY_UL_BUF_CNT_1ST_RELOAD  //17
#define CCCI_TTY_AT_TTL_RGPD_CNT        CCCI_TTY_UL_BUF_CNT_1ST_RELOAD  //17
#define CCCI_TTY_GPS_TTL_RGPD_CNT       CCCI_TTY_UL_BUF_CNT_1ST_RELOAD  //17
#define CCCI_TTY_IMS_TTL_RGPD_CNT       CCCI_TTY_UL_BUF_CNT_1ST_RELOAD  //17
#define CCCI_TTY_SIM_TTL_RGPD_CNT       CCCI_TTY_UL_BUF_CNT_1ST_RELOAD  //17


/* BM reserve QBM_NUM_CCCI_COMM : default (dl+ul) total 76*2 = 152*/
#define TTY_CORE_CONV_RX_RGPD_NUM       (2 *CCCI_TTY_DEV_CNT)            //8
#define CCCI_TTY_UL_TTL_RGPD_REQUEST    (CCCI_TTY_TST_TTL_RGPD_CNT+CCCI_TTY_AT_TTL_RGPD_CNT+CCCI_TTY_GPS_TTL_RGPD_CNT+CCCI_TTY_IMS_TTL_RGPD_CNT) //68
#define CCCI_TTY_DL_TTL_TGPD_REQUEST    CCCI_TTY_UL_TTL_RGPD_REQUEST /* for conv+new(4k) usage */

#define CCCI_TTY_INVALID_GPD_TYPE       QBM_QUEUE_NUM

DCL_STATUS cccitty_ttyc_hdr_cmd_put_bytes_ior(UART_PORT port, ccci_io_request_t *p_ior, module_type ownerid, ccci_io_ext_info_t* pextinfo);
DCL_STATUS cccitty_ttyc_hdr_cmd_clr_rx_buf(UART_PORT port, module_type ownerid, kal_bool check_own);  /* Rx flush handler */
DCL_STATUS cccitty_ttyc_hdr_cmd_assign_rx_ior(UART_PORT port, ccci_io_request_t *p_ior, module_type ownerid); /* Rx reload RGPD request */
void cccitty_ul_deq_hdr(cccitty_dev_t *p_cccidev); /* de-queue hif_ul_q and callback to TTYcore */

#endif //#ifndef _CCCITTY_DATA_H
