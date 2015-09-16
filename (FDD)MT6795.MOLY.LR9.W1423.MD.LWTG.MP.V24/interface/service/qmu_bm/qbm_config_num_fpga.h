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
 *   qbm_config_num_fpga.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
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
 ****************************************************************************/
#ifndef  QMU_BM_CONFIG_NUM_FPGA_INC
#define  QMU_BM_CONFIG_NUM_FPGA_INC

/*  
 *  FPGA QBits measured by Ming.
QBM_TYPE_HIF_DL/HIF_DEQ/HIF_TYPE_TX/NORMAL_ENQ
GPD Count                         : 10   : 20   : 30    : 40    : 50    : 60    : 70    : 80    : 90    : 100
hif_set_gpd() start queue (Qbit)  : 106  : 137  : 176   : 232   : 281   : 331   : 386   : 428   : 479   : 539
hif_set_gpd() resume queue (Qbit) : 69   : 116  : 163   : 210   : 269   : 316   : 360   : 425   : 463   : 511
hif_poll_queue() deq/freeq (Qbit) : 48,5 : 74,5 : 109,4 : 148,4 : 173,4 : 205,5 : 237,5 : 269,4 : 302,4 : 341,5
hif_flush_gpd() freeq (Qbit)      : 19,9 : 12,8 : 11,9  : 11,9  : 11,9  : 13,8  : 12,8  : 13,9  : 12,8  : 12,8
qbmt_alloc_q_no_tail() (Qbit)     : 40   : 66   : 95    : 126   : 155   : 184   : 213   : 244   : 284   : 303


QBM_TYPE_HIF_UL_TYPE3 / HIF_FREEQ / HIF_TYPE_RX / NORMAL_ENQ
GPD Count                         : 10      : 20     : 30      : 40       : 50      : 60       : 70       : 80       : 90       : 100
hif_set_gpd() start queue (Qbit)  : 20      : 13     : 13      : 13       : 12      : 13       : 12       : 15       : 13       : 13
hif_set_gpd() resume queue (Qbit) : 13      : 12     : 11      : 11       : 12      : 12       : 12       : 12       : 12       : 12
hif_poll_queue() deq/freeq (Qbit) : 40,11,4 : 70,8,2 : 104,9,4 : 134,12,4 : 176,9,4 : 199,13,4 : 232,13,4 : 273,15,5 : 298,15,5 : 327,15,4
hif_flush_gpd() freeq (Qbit)      : 15,9    : 11,8   : 12,8    : 12,8     : 12,8    : 12,9     : 11,9     : 12,9     : 13,8     : 12,9
qbmt_alloc_q_no_tail() (Qbit)     : 36      : 66     : 92      : 124      : 153     : 184      : 214      : 245      : 282      : 310

for FPGA we choose 10 for UL, 20 for DL for first.
Buffer operation 
Allocate -> De-Q ->En-Q->FreeQ.
UL (10)
36 + 40 + 106 (Use DL start-Q) + 48(Use de-q time=>traverse TGPD list) = 230
DL(20)
66 + 74+137+74 = 351.
Total 351+230 = 581Q.
 *  
 *  TODO use CPU frequency macro to adjust number in chip or in FPGA.
 */
#define QBM_NUM_HIF_UL_TYPE_IN_HIF    5  /* Maximal number of data path uplnk GPD in HIF at any time. */
#define QBM_NUM_HIF_UL_TYPE_01_IN_HIF 5  /* Maximal number of data path uplnk GPD in HIF at any time. */
#define QBM_NUM_HIF_UL_TYPE_02_IN_HIF 5  /* Maximal number of data path uplnk GPD in HIF at any time. */
#define QBM_NUM_HIF_UL_TYPE_S_IN_HIF  5 /* Maximal number of data path uplnk GPD in HIF at any time. */

#define QBM_NUM_HIF_DL_IN_DRB_Q       10

#endif   /* ----- #ifndef QMU_BM_CONFIG_NUM_FPGA_INC  ----- */
