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
 *   ltm_el2_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   message and common structure definition between LTM and EL2 modules.
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
 * 	Integrate change for using OS tick in OA domain
 *
 * removed!
 * removed!
 * modify ulsdu_info structure for ipid
 *
 * removed!
 * removed!
 *
 ****************************************************************************/


#ifndef  LTM_EL2_STRUCT_INC
#define  LTM_EL2_STRUCT_INC

#include "qmu_bm.h"

/**
 * @brief DRB UL-SDU info Header
 *
 * note:
 * - location : in SW control field of BM-header
 */
typedef struct 
{
    /*** this 4 bytes is reserved for UPCM, DO NOT change the location ***/
	kal_uint16 ipid;
	kal_uint16 rsvd;

    /*** Don't change the following 4 bytes layout, because ltm will use 4 bytes write to clean it***/
#define ULSDU_INFO_HEAD_FLAG_PRIORITY   0x01
#define ULSDU_INFO_HEAD_FLAG_CTRL_PDU   0x02
#define ULSDU_INFO_HEAD_FLAG_RETX_WI_SN 0x04
	kal_uint8  flag_bmp;
	kal_uint8  rsv1;
	kal_uint16 ori_hdr_sz;
    /*** Don't change the above 4 bytes layout, because ltm will use 4 bytes write to clean it***/
    /* pad for maintaining original structure when ABS TICK was used */
    kal_uint32 rsv2;
    /* entry tick, it will be filled by ltm using 32-bit OS tick */
    kal_uint32 tick;
    
    /* Tx HFN & SN */
    kal_uint32 pdcp_count;
}drb_ulsdu_info_head_t;
#define GET_ULSDU_INFO_HEAD(_p) ((drb_ulsdu_info_head_t*)QBM_DES_GET_SW_CTRL_FIELD(_p))

/* Get Macros */
#define GET_DRB_ULSDU_PRIDATA(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp & ULSDU_INFO_HEAD_FLAG_PRIORITY) 
#define GET_DRB_ULSDU_CTRLPDU(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp & ULSDU_INFO_HEAD_FLAG_CTRL_PDU) 
#define GET_DRB_ULSDU_RETX(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp & ULSDU_INFO_HEAD_FLAG_RETX_WI_SN) 

/* Set Macros */
#define SET_DRB_ULSDU_PRIDATA(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp |= ULSDU_INFO_HEAD_FLAG_PRIORITY) 
#define SET_DRB_ULSDU_CTRLPDU(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp |= ULSDU_INFO_HEAD_FLAG_CTRL_PDU) 
#define SET_DRB_ULSDU_RETX(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp |= ULSDU_INFO_HEAD_FLAG_RETX_WI_SN) 

/* Clear Macros */
#define CLR_DRB_ULSDU_PRIDATA(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp &= ~ULSDU_INFO_HEAD_FLAG_PRIORITY) 
#define CLR_DRB_ULSDU_CTRLPDU(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp &= ~ULSDU_INFO_HEAD_FLAG_CTRL_PDU) 
#define CLR_DRB_ULSDU_RETX(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp &= ~ULSDU_INFO_HEAD_FLAG_RETX_WI_SN) 
#define CLR_DRB_ULSDU_FLAG_BMP(_p) \
           (GET_ULSDU_INFO_HEAD(_p)->flag_bmp = 0)


#endif   /* ----- #ifndef LTM_EL2_STRUCT_INC ----- */

